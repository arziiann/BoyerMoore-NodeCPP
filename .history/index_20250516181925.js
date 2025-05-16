import path from 'path';
import { fileURLToPath } from 'url';
import express from 'express';

// __dirname compatibility (ESM-ում չկա by default)
const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

// Load compiled C++ addon
const searchAddon = await import(path.join(__dirname, './build/Release/search.node'));

// Setup Express app
const app = express();
app.use(express.json());

app.post('/search', (req, res) => {
  const { text, pattern } = req.body;

  if (!text || !pattern) {
    return res.status(400).json({ error: 'Missing text or pattern' });
  }

  const result = searchAddon.search(text, pattern);
  res.json({ found: result.length > 0, positions: result });
});

app.listen(3000, () => {
  console.log('🚀 Server running on http://localhost:3000');
});
