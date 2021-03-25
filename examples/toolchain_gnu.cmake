set(OLEVEL O)
set(DEBUG 1)
set(__GNU__)
set(GNU_TOOLCHAIN_ROOT /home/wang/Documents/myfolder/arc_gnu_2019.03_prebuilt_elf32_be_linux_install/bin)


if(${DEBUG} EQUAL 1)
    set(DEBUG_OPTION 1)
    set_property(GLOBAL PROPERTY ${DEBUG_OPTION})
endif()

set(MAP 1)
if(${MAP} EQUAL 1)
    set(LMAP_OPTION -W1,-M,-MAP=${APPL_FULL_NAME}.map)
    set_property(GLOBAL PROPERTY ${LMAP_OPTION})
endif()

set(HEAP_DEFINES 0)
if(DEFINED HEAPSZ)
    add_definitions(-D _HEAPSIZE=${HEAPSZ})
else()
    add_definitions(-D _HEAPSIZE=${DEFUALT_HEAPSZ})
endif()

set(STACK_DEFINES 0)
if(DEFINED STACKSZ)
    add_definitions(-D _STACKSIZE=${STACKSZ})
else()
    add_definitions(-D_STACKSIZE=${DEFUALT_STACKSZ})
endif()

add_definitions(-D __GNU__)

list(GET SUPPORT_OLEVELS O O0 O1 O2 O3 Os Os1 Oz Ofast Og)

if(DEFINED OLEVEL)
    if(${OLEVEL} IN_LIST SUPPORT_OLEVELS)
        set(OPT_OLEVEL -${OLEVEL})
    else()
        set(OPT_OLEVEL "")
    endif()
else()
    set(OPT_OLEVEL "")

endif()

set(CC arc-elf32-gcc)
set(CXX arc-elf32-g++)
set(AS arc-elf32-as)
set(DMP arc-elf32-objdump)
set(LD arc-elf32-gcc)
set(AR arc-elf32-ar)
set(NM arc-elf32-nm)
set(OBJCOPY arc-elf32-objcopy)
set(ELF2HEX arc-elf32-objcopy)
set(SIZE arc-elf32-size)


if(DEFINED GNU_TOOLCHAIN_ROOT)

    set(CC ${GNU_TOOLCHAIN_PREFIX}/${CC})
    set(CXX ${GNU_TOOLCHAIN_PREFIX}/${CXX})
    set(AS ${GNU_TOOLCHAIN_PREFIX}/${AS})
    set(DMP ${GNU_TOOLCHAIN_PREFIX}/${DMP})
    set(LD ${GNU_TOOLCHAIN_PREFIX}/${LD})
    set(AR ${GNU_TOOLCHAIN_PREFIX}/${AR})
    set(NM ${GNU_TOOLCHAIN_PREFIX}/${NM})
    set(OBJCOPY ${GNU_TOOLCHAIN_PREFIX}/${OBJCOPY})
    set(ELF2HEX ${GNU_TOOLCHAIN_PREFIX}/${OBJCOPY})
    set(SIZE ${GNU_TOOLCHAIN_PREFIX}/${SIZE})

else()
    set(MAKE make)
    set(DBG arc-elf32-gdb)
    set(NSIMDRV nsimdrv)
    set(TCFGEN tcfgen)
    set(TCFTOOL tcftool)
endif()

##openocd
##nsim


