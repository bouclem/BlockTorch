# BlockTorch

## Overview

BlockTorch is a C++ desktop application that provides a visual block-based interface for AI, GPU programming, machine learning, and deep learning. Inspired by Scratch, it makes AI/ML accessible through drag-and-drop blocks while using a Python backend powered by PyTorch, Triton, and Matplotlib.

## Tech Stack

- **Frontend (Desktop UI):** C++ with Qt6
- **Backend (ML/DL):** Python with PyTorch, Triton, Matplotlib
- **Bridge:** C++ ↔ Python interop layer
- **Build System:** CMake

## Project Structure

```
BlockTorch/
├── src/          # C++ source (core, ui, blocks, engine, utils)
├── python/       # Python backend (models, data, training, visualization, utils)
├── assets/       # Visual assets (icons, block graphics)
├── config/       # Configuration files
├── tests/        # C++ and Python tests
├── docs/         # Documentation
├── scripts/      # Build & utility scripts
└── third_party/  # External dependencies
```

## Roadmap

- **v0.0.1** — Project scaffolding (folders, .gitkeep, .gitignore)
- **v0.0.2** — CMake build system, documentation
- **v0.1.0** — Choose datasets (HF datasets), choose params, choose architecture (transformer)

## License

TBD
