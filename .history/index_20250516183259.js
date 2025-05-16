import express from 'express';
import path from 'path';
import { fileURLToPath } from 'url';
import { createRequire } from 'module';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const require = createRequire(import.meta.url);

const searchAddon = require('./addon/build/Release/search.node');

const app = express();
app.use(express.json());

app.get('/', (req, res) => {
    res.send('🚀 Boyer-Moore API is running. Use POST /search');
  });
  

app.post('/search', (req, res) => {
  const { text, pattern } = req.body;
  if (!text || !pattern) {
    return res.status(400).json({ error: 'Missing text or pattern' });
  }

  const positions = searchAddon.search(text, pattern);
  res.json({ found: positions.length > 0, positions });
});

app.listen(3000, () => {
  console.log('✅ Server running at http://localhost:3000');
});
