#pragma once
#include <qt5/QtGui/QOpenGLFunctions>
#include <qt5/QtGui/QOpenGLWindow>


class Window : public QOpenGLWindow, protected QOpenGLFunctions
{
    Q_OBJECT

    // OpenGL Events
public:
    ~Window();

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void teardownGL();

private:
    // Private Helpers
    void printContextInformation();
};
