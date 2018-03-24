#
# Created by makemake (Ubuntu Dec 13 2017) on Fri Dec 15 18:19:38 2017
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s .S
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.S.s:
		$(CPP) -o $*.s $<
.s.o:
		$(COMPILE.s) -o $@ $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

AS =		as
CC =		cc
CXX =		c++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.s = $(AS) $(ASFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
CPP = $(CPP) $(CPPFLAGS)
########## Flags from header.mak

#
# This header.mak file sets up all the necessary options for compiling
# and linking C and C++ programs which use OpenGL, GLFW, and/or GLEW on
# the CS Ubuntu systems.  To use it, place it in the same directory as
# your source code, and run the command
#
#	gmakemake > Makefile
#
# To compile and link your program, just run "make".
#

# locations of important directories if the header files
# and library files aren't in the standard places
INCLUDE = -I/usr/include/SOIL
LIBDIRS =

# common linker options
LDLIBS = -lSOIL -lGL -lm -lGLEW -lglfw

# language-specific linker options
CLDLIBS =
CCLDLIBS =

# common compiler flags
COMMONFLAGS = -g $(INCLUDE) -DGL_GLEXT_PROTOTYPES

# language-specific compiler flags
CFLAGS = -std=c99 $(COMMONFLAGS)
CXXFLAGS = $(COMMONFLAGS) -std=c++11

# linker flags
LIBFLAGS = -g $(LIBDIRS) $(LDLIBS)
CLIBFLAGS = $(LIBFLAGS) $(CLDLIBS)
CCLIBFLAGS = $(LIBFLAGS) $(CCLDLIBS)

########## End of flags from header.mak


CPP_FILES =	Buffers.cpp Canvas.cpp Lighting.cpp ShaderSetup.cpp Shapes.cpp Textures.cpp Viewing.cpp textingMain.cpp
C_FILES =	
PS_FILES =	
S_FILES =	
H_FILES =	Buffers.h Canvas.h Lighting.h ShaderSetup.h Shapes.h Textures.h Vertex.h Viewing.h
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	Buffers.o Canvas.o Lighting.o ShaderSetup.o Shapes.o Textures.o Viewing.o 

#
# Main targets
#

all:	textingMain 

textingMain:	textingMain.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o textingMain textingMain.o $(OBJFILES) $(CCLIBFLAGS)

#
# Dependencies
#

Buffers.o:	Buffers.h Canvas.h Vertex.h
Canvas.o:	Canvas.h Vertex.h
Lighting.o:	Lighting.h
ShaderSetup.o:	ShaderSetup.h
Shapes.o:	Canvas.h Shapes.h Vertex.h
Textures.o:	Textures.h
Viewing.o:	Viewing.h
textingMain.o:	Buffers.h Canvas.h Lighting.h ShaderSetup.h Shapes.h Textures.h Vertex.h Viewing.h

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm -f $(OBJFILES) textingMain.o core

realclean:        clean
	-/bin/rm -f textingMain 
