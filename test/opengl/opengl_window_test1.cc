#include "opengl_window_test1.h"
#include <qt5/QtCore/QDebug>
#include <qt5/QtCore/QString>
#include <qt5/QtGui/QOpenGLFunctions>
#include <qt5/QtGui/QOpenGLWindow>
#include <qt5/QtGui/QGuiApplication>

Window::~Window()
{
    makeCurrent();
    teardownGL();
}

/*******************************************************************************
 * OpenGL Events
 ******************************************************************************/

void Window::initializeGL()
{
    // Initialize OpenGL Backend
    initializeOpenGLFunctions();
    printContextInformation();

    // Set global information
    glClearColor(0.0f, 0.0f, 0.0, 1.0f);
}

void Window::resizeGL(int width, int height)
{
    // Currently we are not handling width/height changes
    (void)width;
    (void)height;
}

void Window::paintGL()
{
    // Clear
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::teardownGL()
{
    // Currently we have no data to teardown
}

/*******************************************************************************
 * Private Helpers
 ******************************************************************************/

void Window::printContextInformation()
{
    QString glType;
    QString glVersion;
    QString glProfile;

    // Get Version Information
    glType = (context()->isOpenGLES()) ? "OpenGL ES" : "OpenGL";
    glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));

    // Get Profile Information
#define CASE(c)             \
    case QSurfaceFormat::c: \
        glProfile = #c;     \
        break

    switch (format().profile())
    {
        CASE(NoProfile);
        CASE(CoreProfile);
        CASE(CompatibilityProfile);
    }
#undef CASE

    // qPrintable() will print our QString w/o quotes around it.
    qDebug() << qPrintable(glType) << qPrintable(glVersion) << "("
             << qPrintable(glProfile) << ")";
}

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  // Set OpenGL Version information
  // Note: This format must be set before show() is called.
  QSurfaceFormat format;
  format.setRenderableType(QSurfaceFormat::OpenGL);
  format.setProfile(QSurfaceFormat::CoreProfile);
  format.setVersion(3,3);

  // Set the window up
  Window window;
  window.setFormat(format);
  window.resize(QSize(800, 600));
  window.show();

  return app.exec();
}

