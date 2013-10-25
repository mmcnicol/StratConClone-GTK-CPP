#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=gcc
CXX=gcc
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/city.o \
	${OBJECTDIR}/src/city_list.o \
	${OBJECTDIR}/src/game_engine.o \
	${OBJECTDIR}/src/grid.o \
	${OBJECTDIR}/src/island_list.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/pieces.o \
	${OBJECTDIR}/src/unit_ref.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wall `pkg-config --cflags gtk+-2.0` \
`pkg-config --libs gtk+-2.0` -lstdc++ 
CXXFLAGS=-Wall `pkg-config --cflags gtk+-2.0` \
`pkg-config --libs gtk+-2.0` -lstdc++ 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/stratconclone-gtk-cpp

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/stratconclone-gtk-cpp: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/stratconclone-gtk-cpp ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/city.o: src/city.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -I/usr/include/gtk-2.0/ -I/usr/include/glib-2.0 -I/usr/include/freetype2 -I/usr/lib/i386-linux-gnu/glib-2.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/city.o src/city.cpp

${OBJECTDIR}/src/city_list.o: src/city_list.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -I/usr/include/gtk-2.0/ -I/usr/include/glib-2.0 -I/usr/include/freetype2 -I/usr/lib/i386-linux-gnu/glib-2.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/city_list.o src/city_list.cpp

${OBJECTDIR}/src/game_engine.o: src/game_engine.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -I/usr/include/gtk-2.0/ -I/usr/include/glib-2.0 -I/usr/include/freetype2 -I/usr/lib/i386-linux-gnu/glib-2.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/game_engine.o src/game_engine.cpp

${OBJECTDIR}/src/grid.o: src/grid.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -I/usr/include/gtk-2.0/ -I/usr/include/glib-2.0 -I/usr/include/freetype2 -I/usr/lib/i386-linux-gnu/glib-2.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/grid.o src/grid.cpp

${OBJECTDIR}/src/island_list.o: src/island_list.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -I/usr/include/gtk-2.0/ -I/usr/include/glib-2.0 -I/usr/include/freetype2 -I/usr/lib/i386-linux-gnu/glib-2.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/island_list.o src/island_list.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -I/usr/include/gtk-2.0/ -I/usr/include/glib-2.0 -I/usr/include/freetype2 -I/usr/lib/i386-linux-gnu/glib-2.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/pieces.o: src/pieces.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -I/usr/include/gtk-2.0/ -I/usr/include/glib-2.0 -I/usr/include/freetype2 -I/usr/lib/i386-linux-gnu/glib-2.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/pieces.o src/pieces.cpp

${OBJECTDIR}/src/unit_ref.o: src/unit_ref.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -I/usr/include/gtk-2.0/ -I/usr/include/glib-2.0 -I/usr/include/freetype2 -I/usr/lib/i386-linux-gnu/glib-2.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/unit_ref.o src/unit_ref.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/stratconclone-gtk-cpp

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
