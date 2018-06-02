# Qt Input Method for Onboard


This is a simple Qt Input method that simply triggers [Onboard](https://launchpad.net/onboard) when an input element is focused.

The code is heavily based on [this excellent tutorial how to write touch keyboard in Qt](https://www.kdab.com/qt-input-method-virtual-keyboard/).
The CMake script is based on the CMake script of [attente/input-method-switcher](https://github.com/attente/input-method-switcher).


## Installation

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j
sudo make install
```

## Usage

To use this input method plugin, set `QT_IM_METHOD` to `onboard`.
For example you can add

```
export QT_IM_METHOD=onboard
```

to `~/.profile`.

## Limitations

Onboard only exposes simple show/hide methods.
It is therefore not possible to detect if an external keyboard is attached as it is done in Onboard itself.
Further, if directly afterwards a Gtk3 input element is focused where Onboard is triggered automatically, Onboard sometimes stays hidden as Onboard remembers the hidden status.
