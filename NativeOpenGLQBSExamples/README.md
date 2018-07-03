# Quad Buffered Stereo Examples

These are two QuadBufferedStereo Examples which I came across while digging about  3d Vision OpenGL Examples. This examples are really helpful if someone wants to know how the basic stereo rendering in OpenGL works

## QuadBufferedStereo:
- [QuadBufferedStereo Source](https://github.com/iebeid/quad-buffered-stereo "Example1 Source") can be found here.
- This Example is originally based on  [Ipers](http://www.gali-3d.com/archive/articles/StereoOpenGL/StereoscopicOpenGLTutorial.php "Ipers") example
- The above Example does not render correctly in one eye

## QBSStereo:
- The second example is taken from [OpenGL forum page](https://www.opengl.org/discussion_boards/archive/index.php/t-171258.html "OpenGL forum page")
- This example runs perfectly


###Requirements:
Visual Studio 2017 Community
Windows SDK 10.0.17134.0
OpenGL Dependancy Libraries:
- gl.h
- glu.h
- glut.h


###### Note:Since the include is given like this GL\glut.h you will need to create GL folder in "C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\um\gl" to make above examples run