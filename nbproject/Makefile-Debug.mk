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
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
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
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/cpp/core/exceptions/BaseException.o \
	${OBJECTDIR}/src/cpp/core/exceptions/InstancingException.o \
	${OBJECTDIR}/src/cpp/core/nfa/state/BaseState.o \
	${OBJECTDIR}/src/cpp/core/util/rtti/ObjectFactory.o \
	${OBJECTDIR}/src/cpp/test/TestRTTIClass.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11
CXXFLAGS=-std=c++11

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nfalite

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nfalite: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nfalite ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDEBUG -Isrc/cpp -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/cpp/core/exceptions/BaseException.o: src/cpp/core/exceptions/BaseException.cpp
	${MKDIR} -p ${OBJECTDIR}/src/cpp/core/exceptions
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDEBUG -Isrc/cpp -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/cpp/core/exceptions/BaseException.o src/cpp/core/exceptions/BaseException.cpp

${OBJECTDIR}/src/cpp/core/exceptions/InstancingException.o: src/cpp/core/exceptions/InstancingException.cpp
	${MKDIR} -p ${OBJECTDIR}/src/cpp/core/exceptions
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDEBUG -Isrc/cpp -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/cpp/core/exceptions/InstancingException.o src/cpp/core/exceptions/InstancingException.cpp

${OBJECTDIR}/src/cpp/core/nfa/state/BaseState.o: src/cpp/core/nfa/state/BaseState.cpp
	${MKDIR} -p ${OBJECTDIR}/src/cpp/core/nfa/state
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDEBUG -Isrc/cpp -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/cpp/core/nfa/state/BaseState.o src/cpp/core/nfa/state/BaseState.cpp

${OBJECTDIR}/src/cpp/core/util/rtti/ObjectFactory.o: src/cpp/core/util/rtti/ObjectFactory.cpp
	${MKDIR} -p ${OBJECTDIR}/src/cpp/core/util/rtti
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDEBUG -Isrc/cpp -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/cpp/core/util/rtti/ObjectFactory.o src/cpp/core/util/rtti/ObjectFactory.cpp

${OBJECTDIR}/src/cpp/test/TestRTTIClass.o: src/cpp/test/TestRTTIClass.cpp
	${MKDIR} -p ${OBJECTDIR}/src/cpp/test
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDEBUG -Isrc/cpp -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/cpp/test/TestRTTIClass.o src/cpp/test/TestRTTIClass.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
