# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  C867_config = debug

else ifeq ($(config),release)
  C867_config = release

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := C867

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

C867:
ifneq (,$(C867_config))
	@echo "==== Building C867 ($(C867_config)) ===="
	@${MAKE} --no-print-directory -C . -f C867.make config=$(C867_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f C867.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   C867"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"