
# message(${VALID_TCF})

# if(${VALID_TCF} STREQUAL "")
# 	set(CORE_ARG_FILES "")
# else()

# 	add_definitions(-D EMBARC_TCF_GENERATED)
# endif()

add_definitions(-D PLATFORM_EMBARC)
# message(${EMBARC_GENERATED_DIR})