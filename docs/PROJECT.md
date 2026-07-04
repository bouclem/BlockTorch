# Project Architecture

## What It Is

BlockTorch is a visual, block-based desktop application for AI/ML/DL development. Users compose machine learning pipelines by dragging and connecting blocks — similar to Scratch — while a Python backend (PyTorch, Triton, Matplotlib) handles execution.

## Architecture

### C++ Frontend (Qt6)

- **`src/core/`** — Application lifecycle, state management, project save/load
- **`src/ui/`** — Main window, canvas, block palette, property panels
- **`src/blocks/`** — Block type definitions, block registry, connection logic
- **`src/engine/`** — C++ ↔ Python bridge: spawns Python process, sends block graph, receives results
- **`src/utils/`** — Shared C++ utilities (logging, config parsing, file I/O)

### Python Backend

- **`python/models/`** — Model architecture definitions (transformer first, expandable)
- **`python/data/`** — Dataset loading via HuggingFace datasets
- **`python/training/`** — Training loops, optimizers, checkpointing
- **`python/visualization/`** — Matplotlib-based training plots and metrics
- **`python/utils/`** — Shared Python utilities

### Data Flow

```
User (blocks) → C++ UI → Engine (bridge) → Python backend → PyTorch/Triton
                                         ← Results/Plots ←
```

### Design Principles

1. **Simplicity first** — Visual interface must be intuitive for non-programmers
2. **Modularity** — Each block category is a separate module; easy to extend
3. **Separation of concerns** — C++ handles UI, Python handles ML execution
4. **Extensibility** — New architectures and block types added without core changes

## Direction

- **v0.1.0:** Minimal viable flow — dataset → params → transformer → train
- **Future:** GPU/Triton blocks, more architectures, plugin system, model marketplace
