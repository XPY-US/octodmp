# Credoxy — static release site

A GitHub Pages-friendly release listing inspired by the supplied screenshot. It uses plain HTML, CSS, and JavaScript—no build tools or dependencies.

## 1. Add your files

Put the files you want to distribute inside `downloads/`. The sample filenames in `files.json` are examples; replace them with your real filenames and paths.

Example:
```text
credoxy-site/
├── index.html
├── styles.css
├── app.js
├── files.json
└── downloads/
    ├── hyperion.hpp
    ├── offsets.hpp
    ├── structs.hpp
    └── payload.7z
```

## 2. Edit the release list

Open `files.json`. Each version has a `name`, `date`, and `files` array.

Each file entry supports:
- `name`: filename displayed on the page
- `size`: display text, such as `50 kb` or `37 mb`
- `path`: path to the file under `downloads/`
- `preview`: `true` for text previews, `false` for binary files

Only add files you own or are authorized to distribute. Do not commit API keys, passwords, private dumps, or other secrets to a public repository.

## 3. Publish with GitHub Pages

1. Create a new GitHub repository.
2. Upload the contents of this folder to the repository root.
3. Open **Settings → Pages**.
4. Under **Build and deployment**, choose **Deploy from a branch**.
5. Select `main` and `/ (root)`, then save.
6. Wait for GitHub Pages to publish the site. Your public URL will appear in the Pages settings.

## Important limitations

- This is a static site. The API key and logout controls are explanatory placeholders, not real authentication.
- Anyone who can access the public site can access files committed in `downloads/`.
- GitHub repositories have file-size limits, and GitHub Pages is not intended for large binary distribution. For large archives, use an appropriate file-hosting or release service and link to those files.
- Text preview uses the browser's `fetch`, so it works when hosted over HTTP(S), such as GitHub Pages. It may not work when opening `index.html` directly as a local file; use a local static server for testing.
