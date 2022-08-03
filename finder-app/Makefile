ifndef CROSS_COMPILE
 CC:=gcc
else
 ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
 CC:=aarch64-none-linux-gnu-gcc
 endif
endif
CFLAGS = -Wall

default:
	$(CC) $(CFLAGS) -o writer writer.c

clean:
	rm writer
	rm *.o || true
