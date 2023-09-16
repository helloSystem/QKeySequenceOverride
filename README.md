# QKeySequenceOverride

![image](https://user-images.githubusercontent.com/2480569/137368240-56cccc96-e565-43f0-8590-966b467e7f4f.png)

This repo contains a tiny bit (~30 lines) of C++ code which compiles to a `.so` file to dynamically override the `QKeySequence::toString()` function in Qt to represent shortcuts with graphical symbols similar to the Mac.

## Instructions

On FreeBSD:

```
cd QKeySequenceOverride
mkdir build
cd build
qmake6 ..
make
env LD_PRELOAD=$(readlink -f libQKeySequenceOverride.so.1.0.0) menubar
```

## LD_PRELOAD
The heart of this trick involves using `LD_PRELOAD`.  For an explanation of this powerful feature of the dynamic linker, check out [this writeup](https://rafalcieslak.wordpress.com/2013/04/02/dynamic-linker-tricks-using-ld_preload-to-cheat-inject-features-and-investigate-programs/).

For more advanced `LD_PRELOAD` tricks check [this out](http://www.goldsborough.me/c/low-level/kernel/2016/08/29/16-48-53-the_-ld_preload-_trick/).

## Credits

https://github.com/heavyimage/OverrideQtSplashscreen/
