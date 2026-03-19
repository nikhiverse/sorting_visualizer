# Sorting Visualizer

A web-based sorting algorithm visualizer that demonstrates various sorting algorithms in real-time. This project uses C++ backend compiled to WebAssembly (WASM) for efficient sorting operations, coupled with a Vanilla JavaScript frontend to render the step-by-step visualization.

## Features

- **Real-time Visualization:** Watch the sorting process happen step-by-step.
- **Multiple Algorithms:** Visualize 9 different sorting algorithms.
- **Interactive Controls:**
  - Adjust the number of bars (array size).
  - Control the execution speed (0.5x, 1x, 2x, 4x).
  - Generate new random arrays.
  - Reverse the sorted array.
- **Detailed Statistics:** Track the number of swaps and comparisons in real-time.
- **Color-coded Legend:** Easily differentiate between unsorted, comparing, swapping, pivot, and sorted elements.

## Supported Algorithms

- Bubble Sort
- Insertion Sort
- Selection Sort
- Quick Sort
- Heap Sort
- Merge Sort
- Shell Sort
- Tim Sort
- Tree Sort

## Technologies Used

- **Frontend:** HTML5, CSS3, Vanilla JavaScript
- **Backend/Algorithms:** C++
- **Compilation:** WebAssembly (WASM) via Emscripten SDK

## How it Works

The core sorting logic is written in C++ for optimal performance. The Emscripten SDK `emcc` compiles the C++ codebase (`sorting.cpp` and related files) into WebAssembly (`sorting.wasm`) and provides a JavaScript glue file (`sorting.js`). 

The frontend JavaScript interacts with the WASM module to retrieve the array elements and the step-by-step history of comparisons and swaps, which are then rendered as DOM elements with varying heights and colors.

## Project Structure

- `index.html`: The main user interface.
- `app.js`: Main JavaScript application logic handling the UI and visualization loop.
- `style.css`: Stylesheet for the visualizer.
- `sorting.cpp`, `array.cpp`, `sorting.h`: Main C++ entry points and headers for WebAssembly compilation.
- `algo/`: Directory containing individual C++ implementations for each sorting algorithm.
- `build.sh`: Bash script to compile the C++ code to WebAssembly using Emscripten.

## Instructions to Build

If you want to modify the C++ source code and recompile to WebAssembly, you need to have the Emscripten SDK installed and activated in your terminal environment.

1. Ensure Emscripten environment variables are loaded:
   ```bash
   source ~/emsdk/emsdk_env.sh
   ```
2. Run the build script:
   ```bash
   ./build.sh
   ```
This will regenerate `sorting.js` and `sorting.wasm`.

## Running the Application

Since the project uses WebAssembly, it must be served over a local web server (cannot be easily opened directly via an `file://` protocol in all browsers).

You can use any local server, for example with Python:

```bash
python3 -m http.server 8000
```

Then open `http://localhost:8000` in your web browser.

## Author

Created by [rathodnk](https://www.linkedin.com/in/rathodnk/)
Contact: [nikhil.webdna@gmail.com](mailto:nikhil.webdna@gmail.com)
>>>>>>> 9e83c39 (read)
