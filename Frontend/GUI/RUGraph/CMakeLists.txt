set(GraphGUI_src_files
	Graphable.cpp
	Graphable.h
	GraphLine.cpp
	GraphLine.h
	GraphScatter.cpp
	GraphScatter.h
	Circle.cpp
	Circle.h
	RUGraph.cpp
	RUGraph.h
	RUDrawComponent.cpp
	RUDrawComponent.h
)
add_library(GraphGUI ${GraphGUI_src_files})

install(TARGETS GraphGUI EXPORT gfxConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})

install(EXPORT gfxConfig DESTINATION share/glades/cmake)

export(TARGETS GraphGUI FILE gfxConfig.cmake)
