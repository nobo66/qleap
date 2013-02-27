# QLeap

Qt bindings for leap motion device. More info at [QLeap's homepage](http://jwintz.github.com/qleap).

### Caveats

Qt 5.0.0 does not fully supports gesture, especially on mac. The
current implementation somehow fixes that, but Qt 5.1.0 will
introduces necessary features for the development of QLeap.

### Build and test

Even though illustrated with ninja, Unix Makefiles or other generators
can be used without problems.

    $ cd /path/to/qleap
    $ mkdir build
    $ cd build
    $ cmake .. -G Ninja
    $ ninja
    $ ninja test

### Current features

- QLeapMapper maps to screen, scene and space (respectively for
  QtWidgets, QtDeclarative and raw coordinates handling)
