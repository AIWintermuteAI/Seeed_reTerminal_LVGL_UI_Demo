# Seeed_reTerminal_LVGL_UI_Demo
Demo code for sample reTerminal UI application, written in C with LVGL 8.0

<p align="center">
<img alt="fft" src="resources/lvgl_reterminal.gif" width="100%">
</p>

For more details, visit [Seeed Wiki](https://wiki.seeedstudio.com/reTerminal-build-UI-using-LVGL/)


## Requirements

* **SDL** a low level driver library to use graphics, handle mouse, keyboard etc.

## Usage

### Get the project

Clone the PC project and the related sub modules:

```
git clone --recursive https://github.com/AIWintermuteAI/Seeed_reTerminal_LVGL_UI_Demo.git
```

### Install SDL

```
sudo apt-get update && sudo apt-get install -y build-essential libsdl2-dev
```

## CMake

The following steps can be used with CMake on a Unix-like system.

1. Ensure CMake is installed, i.e. the `cmake` command works on the terminal.
2. Make a new directory. The name doesn't matter but `build` will be used for this tutorial.
3. Type `cd build`.
4. Type `cmake ..`. CMake will generate the appropriate build files.
5. Type `make -j4` or (more portable) `cmake --build . --parallel`.

**NOTE:** `--parallel` is supported from CMake v3.12 onwards. If you are using an older version of CMake, remove `--parallel` from the command or use the make option.

6. The binary will be in `../bin/main`, and can be run by typing that command.

## Contributing
1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request!

If you find an issue, please report it via GitHub!