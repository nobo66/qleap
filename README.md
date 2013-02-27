# qleap

Qt bindings for leap motion device.

### Build and test

    $ cd /path/to/qleap
    $ mkdir build
    $ cd build
    $ cmake .. -G Ninja
    $ ninja
    $ ninja test

### Current features

- QLeapMapper maps to screen, scene and space (respectively for QtWidgets, QtDeclarative and raw coordinates handling)
