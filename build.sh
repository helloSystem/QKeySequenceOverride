clang++ -std=c++17 -c -DQT_NO_VERSION_TAGGING -pipe -fPIC -o0 -g -Wall -Wextra -pthread -fPIC -DQT_GUI_LIB -DQT_CORE_LIB  ./override.cpp   -o override.o -I /usr/local/include/qt6  -I /usr/local/include/qt6/QtGui -I /usr/local/include/qt6/QtCore
clang++ -o0 -g -pthread  -Wl,-undefined-dynamic-lookup, -shared -Wl,-soname,libQKeySequenceOverride.so.1 -o build/libQKeySequenceOverride.so.1.0.0 override.o -lc



