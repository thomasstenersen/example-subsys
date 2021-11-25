# Example: Build and deploy a static library with the nRF Connect SDK toolchain


## Install

Clone this repository using [`west`](https://github.com/zephyrproject-rtos/west):

``` sh
west init -m https://github.com/thomasstenersen/example-subsys
west update
```

Hint: To speed this up, you can clone the repositories without history by adding `-o=--depth=1` to the `west update` command above.


## Build
The project can be built with `west` or using CMake:

``` sh
west build -b nrf52840dk_nrf52840 --cmake-only applications/library_build

# alternatively with CMake
cmake -GNinja -Sapplications/library_build -Bbuild -DBOARD=nrf52840dk_nrf52840
```

Then build the library:

``` sh
cd build
ninja mylib
```
