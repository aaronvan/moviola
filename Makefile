#############
## Moviola ##
#############

# use gmake

CC       = clang
CFLAGS   = -Wall -Werror -g -c -Iinclude -std=c17 -pedantic
CPPFLAGS = -I/usr/local/include
LDFLAGS  = -L/usr/local/lib
LDLIBS   = -ljson-c -lcurl
BINDIR	 = bin
SRCDIR   = src
SRCS     = $(wildcard $(SRCDIR)/*.c)
OBJDIR   = obj
OBJ      = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
TARGET   = $(BINDIR)/moviola
VERIFY	 = cat -e -t -v Makefile

# default target
all: build $(TARGET)
	
# Create object and binaries directory if they don't exist
build:
	mkdir -p $(OBJDIR) $(BINDIR)

# Rule to build the object files in the obj directory
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	
# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean	
clean:
	@echo "Cleaning up..."
	rm -rf $(OBJDIR) $(BINDIR) $(TARGET)

.PHONY: verify
verify:
	$(VERIFY)
	
run:
	@./$(TARGET)
