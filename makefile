# This version of the makefile seems correctly includes
# header file dependencies, and will re-build
# .o files if any of the included .h files change
# It also assumes that raylib has been cloned to a 
# directory at the same level as the Europi directory
# and that raylib has been compiled with using the 
# following command from within the ../raylib/src directory:
#    make PLATFORM=PLATFORM_RPI
# this builds ../raylib/release/rpi/libraylib.a
OBJS := europi.o europi_func1.o europi_func2.o europi_gui.o
INCLUDES = -I. -I../raylib/src -I../raylib/src/external -I../raylib/release/libs/rpi -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads
#LIBS = -lpigpio -lrt -lraylib -lGLESv2 -lEGL -lpthread -lrt -lm -lbcm_host -lopenal
LIBS = -lpigpio -lraylib -lbrcmGLESv2 -lbrcmEGL -lpthread -lrt -lm -lbcm_host -lopenal
LFLAGS = -L. -L../raylib/src -L../raylib/release/libs/rpi -L/opt/vc/lib
CFLAGS = -O2 -s -Wall -std=gnu99 -fgnu89-inline -Wno-unused-variable
PLATFORM = PLATFORM_RPI

# link
europi: $(OBJS)
	gcc $(OBJS) $(CFLAGS) $(INCLUDES) $(LFLAGS) $(LIBS) -D$(PLATFORM) -o europi 

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)

# compile and generate dependency info;
# more complicated dependency computation, so all prereqs listed
# will also become command-less, prereq-less targets
#   sed:    strip the target (everything before colon)
#   sed:    remove any continuation backslashes
#   fmt -1: list words one per line
#   sed:    strip leading spaces
#   sed:    add trailing colons
%.o: %.c
	gcc -c $(CFLAGS) $*.c -o $*.o
	gcc -MM $(CFLAGS) $*.c > $*.d
	@cp -f $*.d $*.d.tmp
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmp

# remove compilation products
clean:
	rm -f europi *.o *.d
	
