ifndef CROSS_COMPILE
 CC:=gcc
else
 ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
 CC:=aarch64-none-linux-gnu-gcc
 endif
endif
CFLAGS = -Wall

default: finder-app/writer
	$(CC) $(CFLAGS) -o finder-app/writer finder-app/writer.c

clean:
	rm finder-app/writer
	@rm finder-app/*.o || true
