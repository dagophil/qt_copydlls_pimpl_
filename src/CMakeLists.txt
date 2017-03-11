add_executable(myApp ${APPLICATION_TYPE}
	myApp_main.cxx
	myCustomWidget.cxx
	myMainWindow.cxx
  ${LOGGING_SOURCES}
)

qt5_use_modules(myApp Widgets)
