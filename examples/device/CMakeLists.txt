
SUBDIRLIST(DEV_INCDIR ${EMBARC_OSP}/device/ip)

embarc_osp_include_directories(
  ${EMBARC_OSP}/device
  ${EMBARC_OSP}/device/inc
)

get_property(onchip_ip_list GLOBAL PROPERTY ONCHIP_IP_LIST)

if(onchip_ip_list)
	message("emsk macro define here 2")

	aux_source_directory(${EMBARC_OSP}/arc/device/ip DEV_CSRCDIR)
	foreach(inc ${DEV_INCDIR})
		embarc_osp_include_directories(
			${inc}
		)
	endforeach()
else()
	embarc_osp_include_directories(
		${EMBARC_OSP}/device/ip/ip_hal/inc
	)
endif()

