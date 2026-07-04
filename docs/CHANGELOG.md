# Changelog

## [0.0.6] - 2026-07-04

### Added

- Custom parameter input fields (layers, hidden size, vocab size, seq length, batch size) in right sidebar
- Drag & drop support — drag Start/Stop blocks from left sidebar onto canvas
- Windowed mode (resizable 1280x720, min 800x600) instead of forced fullscreen

### Changed

- Improved sidebar styling (section headers, borders, spacing)
- Right sidebar widened to 280px for param inputs
- Canvas hint text updated for drag & drop

## [0.0.5] - 2026-07-04

### Added

- Start and Stop blocks (first blocks, clickable in left sidebar to add to canvas)
- Block base class with double-click signal
- Right sidebar now shows Params (estimated)
- `src/core/Params.h` / `Params.cpp` — generic parameter estimator with formatting (K/M/B)
- Double-click Start block on canvas triggers param estimation and displays result

## [0.0.4] - 2026-07-04

### Added

- Home view with app name, version, and Workspace button
- Workspace Saves view with empty state and Continue/Back buttons
- Workspace view with canvas, left sidebar (blocks), right sidebar (properties)
- QStackedWidget navigation between views (Home → Saves → Workspace)
- First run starts at Home view

## [0.0.3] - 2026-07-04

### Added

- First application window (dark theme, fullscreen) with "BlockTorch" text
- `src/main.cpp` entry point with QApplication
- `src/ui/MainWindow.h` and `src/ui/MainWindow.cpp`
- `docs/documentation/` folder for app usage docs (gitkeep only)
- Apache 2.0 license (`LICENSE` file at root)

## [0.0.2] - 2026-07-04

### Added

- CMake build system (root, src, tests)
- Project documentation (README, TODO, CHANGELOG, PROJECT, LESSONS, METRICS)
- Qt6 integration in CMake configuration

## [0.0.1] - 2026-07-04

### Added

- Project folder structure with modular layout
- `.gitkeep` files in all empty directories
- `.gitignore` for C++, Python, CMake, and IDE artifacts
