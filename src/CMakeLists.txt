add_executable(myApp
	myApp_main.cxx
	myCustomWidget.cxx
	myMainWindow.cxx
  ${LOGGING_SOURCES}
)

qt5_use_modules(myApp Widgets)
