const versionsContainer = document.getElementById("versions");
const previewDialog = document.getElementById("previewDialog");
const messageDialog = document.getElementById("messageDialog");

document.getElementById("year").textContent = new Date().getFullYear();

function showMessage(title, message) {
  document.getElementById("messageTitle").textContent = title;
  document.getElementById("messageBody").textContent = message;
  messageDialog.showModal();
}

function formatSize(bytes) {
  if (bytes == null) return "";
  if (bytes < 1024) return `${bytes} bytes`;
  if (bytes < 1024 * 1024) return `${(bytes / 1024).toFixed(0)} kb`;
  return `${(bytes / (1024 * 1024)).toFixed(0)} mb`;
}

function safeDownloadPath(path) {
  // Only allow files stored under downloads/; config is intended for trusted files you own.
  return path.startsWith("downloads/") && !path.includes("..") ? path : null;
}

function makeFileRow(file) {
  const row = document.createElement("div");
  row.className = "file-row";

  const meta = document.createElement("div");
  meta.className = "file-meta";
  const name = document.createElement("span");
  name.className = "file-name";
  name.textContent = file.name;
  const size = document.createElement("span");
  size.className = "file-size";
  size.textContent = file.size || "";
  meta.append(name, size);

  const actions = document.createElement("div");
  actions.className = "file-actions";
  const path = safeDownloadPath(file.path);

  if (path) {
    const download = document.createElement("a");
    download.className = "primary-button";
    download.href = path;
    download.download = file.name;
    download.textContent = "download";
    actions.append(download);
  }

  if (file.preview && path) {
    const preview = document.createElement("button");
    preview.className = "secondary-button";
    preview.type = "button";
    preview.textContent = "preview";
    preview.addEventListener("click", () => openPreview(file, path));
    actions.append(preview);
  }

  row.append(meta, actions);
  return row;
}

async function openPreview(file, path) {
  document.getElementById("previewTitle").textContent = file.name;
  const content = document.getElementById("previewContent");
  content.textContent = "Loading preview...";
  previewDialog.showModal();
  try {
    const response = await fetch(path);
    if (!response.ok) throw new Error("Preview unavailable");
    const text = await response.text();
    content.textContent = text.slice(0, 120000);
    if (text.length > 120000) content.textContent += "\n\n[Preview shortened]";
  } catch {
    content.textContent = "This file could not be previewed. It may be binary or too large.";
  }
}

function renderVersions(data) {
  versionsContainer.replaceChildren();
  if (!Array.isArray(data.versions) || data.versions.length === 0) {
    versionsContainer.innerHTML = '<div class="empty">No releases have been added yet.</div>';
    return;
  }

  for (const version of data.versions) {
    const section = document.createElement("section");
    const heading = document.createElement("div");
    heading.className = "version-heading";
    const versionName = document.createElement("span");
    versionName.className = "version-name";
    versionName.textContent = version.name;
    const date = document.createElement("span");
    date.className = "version-date";
    date.textContent = version.date || "";
    heading.append(versionName, date);
    section.append(heading);

    for (const file of version.files || []) section.append(makeFileRow(file));
    versionsContainer.append(section);
  }
}

fetch("files.json")
  .then(response => {
    if (!response.ok) throw new Error("Could not load files.json");
    return response.json();
  })
  .then(renderVersions)
  .catch(() => {
    versionsContainer.innerHTML = '<div class="empty">Could not load releases. Check that <strong>files.json</strong> is in the site root.</div>';
  });

document.getElementById("apiKeyButton").addEventListener("click", () => {
  showMessage("API key", "This is a static GitHub Pages template. Do not put real API keys or secrets in this site. Add a secure backend if you need private account features.");
});
document.getElementById("logoutButton").addEventListener("click", () => {
  showMessage("Static demo", "The account area is a visual placeholder. GitHub Pages does not provide user login or logout by itself.");
});
document.querySelectorAll("[data-close]").forEach(button => {
  button.addEventListener("click", () => document.getElementById(button.dataset.close).close());
});
