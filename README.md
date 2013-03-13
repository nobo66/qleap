# QLeap

Qt bindings for leap motion device. More info at QLeap's [homepage](http://jwintz.github.com/qleap).

### Build and test

Even though illustrated with ninja, Unix Makefiles or other
generators can be used without any problem.

    $ cd /path/to/qleap
    $ mkdir build
    $ cd build
    $ cmake .. -G Ninja
    $ ninja
    $ ninja test

### Done

- **[QLeapGui]** QLeapListener: sends mouse events
- **[QLeapGui]** QLeapListener: sends touch events
- **[QLeapGui]** QLeapMapper: maps to space
- **[QLeapGui]** QLeapMapper: maps to scene
- **[QLeapGui]** QLeapMapper: maps to screen

### Todo

- **[QLeapGui]** QLeapListener: set touch points (pen) flag for tool usage
- **[QLeapGui]** QLeapListener: set custom cursor for widget|window targets
- **[QLeapGui]** QLeapListener: send events on two points
- **[QLeapWidgets]** QLeapGesture
- **[QLeapWidgets]** QLeapGestureRecognizer
- **[QLeapQuick]** QLeapArea
- **[QLeapQuick]** QLeapQuickPlugin
