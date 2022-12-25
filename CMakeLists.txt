include(WiresharkPlugin)

# Plugin name and version info (major minor micro extra)
set_module_info(dissectme 0 0 0 1)

# TODO: Conditionally add dllmain and pch if on win
set(DISSECTOR_SRC
	dissectme.cpp
)

set(PLUGIN_FILES
	plugin.c
	${DISSECTOR_SRC}
)

set_source_files_properties(
	${PLUGIN_FILES}
	PROPERTIES
	COMPILE_FLAGS "${WERROR_COMMON_FLAGS}"
)

register_plugin_files(plugin.c
	plugin
	${DISSECTOR_SRC}
)

add_wireshark_plugin_library(dissectme epan)

target_link_libraries(dissectme epan)

install_plugin(dissectme epan)

file(GLOB DISSECTOR_HEADERS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.h")
CHECKAPI(
	NAME
	  dissectme
	SWITCHES
	SOURCES
	  ${DISSECTOR_SRC}
	  ${DISSECTOR_HEADERS}
)

