# Lessons Learned

Cumulative mistakes, patterns, and insights. Read before starting work.

---

## v0.0.1

- **Folder structure first** — Setting up the full modular layout before writing code prevents restructuring later.
- **`.gitkeep` in every empty folder** — Keeps the folder structure visible in git from day one.

## v0.0.2

- **CMake `AUTOMOC/AUTOUIC/AUTORCC`** — Must be enabled at the top level before adding Qt-dependent targets.
- **CMake 3.21+ for Qt6** — Older CMake versions lack proper Qt6 support.
