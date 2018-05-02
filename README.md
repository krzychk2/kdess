# kdess
KDE Surveillance System

This is small program for KDE that displays RTSP streams from cameras or recorders on Your screen without browser.

Written in KDE Neon/Ubuntu, QT5, C++

## Compile

    make
  

## Configure KDESS

KDESS uses INI like static file.
Example of the ini file is in file: _kdess-example.ini_

## H.264 codec for Ubuntu
In order You get the error from gstreamer - H.264 codec not supported, You need to install codec by Yourself.
In Ubuntu You can do this by:

    apt-get install gstreamer1.0-libav


## RUN

    ./build/KDESS -c kdess-example.ini
  
Enjoy.

## TODO:
Support for Dahua AV codec.
Support for PTZ cameras.
