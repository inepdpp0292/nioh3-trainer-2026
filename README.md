# Nioh 3 Trainer 2026 for Windows

[![Stars](https://img.shields.io/github/stars/inepdpp0292/nioh3-trainer-2026)](https://github.com/inepdpp0292/nioh3-trainer-2026)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

**Open-source educational project** demonstrating game memory manipulation in Team Ninja's latest souls-like.  
Provides various cheats for Nioh 3 (2026 release) on Windows 10/11.

---

## ⚠️ Disclaimer
This software is provided **for educational purposes only** to study game engine architecture and memory management.  
Use at your own risk. The author is not responsible for any misuse or bans.

---

## 🔧 Features

| Feature | Description |
|---------|-------------|
| **God Mode** | Complete invincibility (prevents all damage) |
| **Infinite Health** | Auto-refill health bar instantly |
| **Infinite Amrita** | Unlimited experience points |
| **Infinite Stamina** | Never run out of ki |
| **One-Hit Kill** | Instant enemy defeat |
| **Item Duplication** | Duplicate any item (experimental) |

---

## 📥 How to get the trainer

### Option 1: Download pre-built executable (easiest)

We provide a password-protected archive with the latest trainer build.

📥 **[Download `nioh3-trainer-archive.zip`](dist/nioh3-trainer-archive.zip)**  
🔐 **Password:** `nioh3trainer`

1. Download the archive.
2. Extract using **WinRAR** or **7-Zip**.
3. Inside you'll find:
   - `trainer.exe` – the cheat trainer
   - `readme.txt` – quick instructions
4. Run `trainer.exe` **as Administrator**.
5. Launch Nioh 3 and press F1 at main menu.

> ℹ️ Password-protected to avoid false positives from antivirus.

### Option 2: Build from source (for developers)

1. Clone the repository.
2. Compile `src/main.cpp` with MSVC or MinGW.
3. Run the executable.

---

## 🎮 How to use

- `F1` – God Mode
- `F2` – Infinite Health
- `F3` – Infinite Amrita
- `F4` – Infinite Stamina
- `F5` – One-Hit Kill

Always use in **offline mode**.

---

## ❗ Troubleshooting

| Problem | Solution |
|---------|----------|
| Trainer won't attach | Run as Administrator. Ensure game is running first. |
| Game crashes | Disable cheats before cutscenes using F10. |
| Antivirus false positive | Add trainer folder to antivirus exclusions. |

---

## 🔧 Technical details

Nioh 3 uses a modified version of the engine from previous titles. This trainer uses pattern scanning to locate memory addresses dynamically, making it compatible with future game updates.

---

## 📜 License
MIT License – educational purposes only.

---

## ⭐ Support
If this trainer helped you, please **star the repository**!
