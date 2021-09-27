# qgl, qopengl的使用
QGl是qt4版本的组件，在qt5以后的版本，建议使用qopengl.

# QOpenGLWidget,QOpenGLWindow
QOpenGLWindow renders directly to the window (1 step). QOpenGLWidget renders to an off-screen buffer, then to the widget (2 steps).