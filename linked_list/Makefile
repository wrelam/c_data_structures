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
LIBNAME	:=	linked_list.a
OBJECTS	:=	$(patsubst $(SRCDIR)/%.c,%.o,$(wildcard $(SRCDIR)/*.c))
VPATH	:=	$(SRCDIR)

.SUFFIXES:

.PHONY: all
all: $(LIBNAME)

.PHONY: debug
debug: CFLAGS += $(DBGFLAGS)
debug: clean all

$(LIBNAME): $(OBJECTS)
	$(AR) cr $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(LIBNAME)
