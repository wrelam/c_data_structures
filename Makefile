################################################################################
#
# Makefile
#
# Manages how the project is built
################################################################################
SHELL	:=	/bin/sh
SRCDIR	:=	src
INCDIR	:=	include
CC		:=	gcc
CFLAGS	:= 	-std=iso9899:1999
CFLAGS	+=	-Wall -Wextra -Werror -pedantic
CFLAGS	+=	-I$(INCDIR)
DBGFLAGS:=	-ggdb3 -DDEBUG
LIBNAME	:=	data_structures.a
OBJECTS	:=	$(patsubst $(SRCDIR)/%.c,%.o,$(wildcard $(SRCDIR)/*.c))
SLIBS	:=	$(patsubst $(SRCDIR)/%.c,%.a,$(wildcard $(SRCDIR)/*.c))
VPATH	:=	$(SRCDIR)

.SUFFIXES:

.PHONY: all
all: $(LIBNAME)

.PHONY: debug
debug: CFLAGS += $(DBGFLAGS)
debug: clean all

$(LIBNAME): $(SLIBS)
	$(AR) cr $@ $^

%.a: %.o
	$(AR) cr $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(SLIBS) $(LIBNAME)
