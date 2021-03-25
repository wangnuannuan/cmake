set(SUPPORTED_TOOLCHAINS gnu mw)
## Another define in options.mk
get_property(current_toolchain CACHE TOOLCHAIN PROPERTY VALUE)

if(current_toolchain) 
	if(NOT ${current_toolchain} IN_LIST SUPPORTED_TOOLCHAINS)
		message("Toolchain ${current_toolchain} is not supported, please check it!")
	endif()

else()
	set(current_toolchain "mw")
endif()
include(${EMBARC_OSP}/cmake/toolchain/toolchain_${current_toolchain}.cmake)