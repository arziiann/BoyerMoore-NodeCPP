# 🚀 Boyer-Moore Pattern Search Engine (Node.js + C++)

This project implements a high-performance pattern search engine using the **Boyer-Moore** algorithm written in C++, exposed to Node.js via a native addon.

Perfect for learning:
- 🧠 Efficient string algorithms (Boyer-Moore)
- ⚙️ Native Addons using `node-addon-api`
- 🌐 REST API development in Node.js

---

## 📁 Project Structure
<pre> 

Boyer-Moore/
├── addon/ # C++ code + binding.gyp
│ ├── search.cpp
│ └── binding.gyp
├── build/ # Compiled addon (.node)
├── index.js # Express server using the addon
├── package.json

</pre>

## ⚙️ Prerequisites

- Node.js ≥ 16.x
- C++ compiler (g++, clang, MSVC etc.)
- Python (for node-gyp)
- `node-addon-api` installed via `npm`
- `node-gyp` installed (globally or locally)

---

## 🚀 Installation & Build

```bash
# Install Node dependencies
npm install

# Go into addon folder and build native module
cd addon
npx node-gyp configure build
cd ..
````

---

## 🌐 Run the API Server

```bash
node index.js
```

The server will run at [http://localhost:3000](http://localhost:3000)

---

## 📡 API Endpoint

**POST** `/search`

### Body:

```json
{
  "text": "your full text here",
  "pattern": "word to search"
}
```

### Response:

```json
{
  "found": true,
  "positions": [8, 57, 102]
}
```

---

## 🔬 Example Test (with curl)

```bash
curl -X POST http://localhost:3000/search \
  -H "Content-Type: application/json" \
  -d '{"text": "ababcabcababd", "pattern": "ababd"}'
```

Response:

```json
{ "found": true, "positions": [8] }
```

---

## 🧠 Learnings

* ✅ C++ Boyer-Moore implementation
* ✅ Native Addons using `node-addon-api`
* ✅ Interfacing C++ and JavaScript
* ✅ Fast and efficient string matching
* ✅ RESTful API with Express.js



