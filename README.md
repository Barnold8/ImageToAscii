# Image-to-Ascii

## Why?

> Why not?

## How?

> thanks to the stb library

## Need to know

The program **ONLY** accepts png files, the file extension needs to be in lower case or it wont work. As far as my testing goes, 256x256 images work fine, but higher resolutions should be fine too. To see the image in a text editor, zoom out. The default zoom most likely wont show you the full detail.

## How to use

1. Clone the repo
2. Compile with ``g++ main.cpp``
3. run the exe with the command line arg that is your relative file path

**Example**:

== Command ==

./a.exe "doge.png"

== Input image ==
<img src="images/doge.png" alt="Ascii" width="100"/>

== Output == 
<img src="images/dogeScreenShot.png" alt="Ascii" width="100"/>

## Special thanks!

Thanks to [Nothings's code](https://github.com/nothings/stb), this project was possible.