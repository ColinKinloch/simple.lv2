NAME = simple
CFLAGS       = -fPIC -DPIC -lm
LDFLAGS      = -shared -fPIC -DPIC

UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
	DYLIB := lib$(NAME).dylib
else
	DYLIB := lib$(NAME).so
endif

ifneq (${SYSROOT},"")
	SYSROOT_FLAG := --sysroot="${SYSROOT}"
endif


DEPS := osc.h sine.h mult.h
SRCS := osc.c sine.c mult.c
OBJS := $(addsuffix .o,$(basename $(SRCS)))

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(SYSROOT_FLAG) $< -c -o $@

$(DYLIB): $(OBJS) simple.c
	$(CC) $(LDFLAGS) $(CFLAGS) $(SYSROOT_FLAG) -shared simple.c $(OBJS) -o $@

clean:
	rm *.o *.so

default: $(DYLIB)
