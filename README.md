<!-- <div align="center"> -->
<img src="docs/logo.jpg" width="200">

<!-- </div> -->
# STM32G431CB
Programming an ***STM32G431CB*** microcontroller (the ***B-G431B-ESC1 Discovery kit***) for motor controllers on a three wheeled robot with omnidirectional wheels.

The blinking of the LEDs (linker script, startup, and main) were all adopted/adjusted versions following the tutorial in: https://kleinembedded.com/stm32-without-cubeide-part-1-the-bare-necessities/

---

# Installation & Usage

[How to clone the repo]( https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository?platform=mac#cloning-a-repository)

## Required Packages

* [openocd](https://github.com/openocd-org/openocd)
  > Note the following packages are required to use `openocd`: 
  - make
  - libtool
  - pkg-config >= 0.23 or pkgconf
  - autoconf >= 2.69
  - automake >= 1.14
  - texinfo >= 5.0
  - libusb-1.0.


---

First, in the **root** directory, run:
```
git clone git://git.code.sf.net/p/openocd/code openocd
```

Then go inside the `openocd` directory. Run the following commands sequentially:
> Note for `macos` you need to run: `$ brew install automake` and `$ brew install libusb` for the following to work.
```
./bootstrap
```
```
./configure --enable-stlink
```
```
make
```
```
sudo make install
```

---

## Compiling & Executing

To build the executable in the ***STM32G431CB*** directory, invoke `make`:
```
make
```

Then, to:
- Program the binary to the target
- Verify that it was programmed correctly
- Reset the target
- Exit OpenOCD
run:
```
make flash
```
> `make flash` also builds the executable, as well as flashing to the board 

## Compiling & Executing an Example Script

For the blinky_example, the following would be run in the ***STM32G431CB*** directory:
```
make blinky_example_flash
```
