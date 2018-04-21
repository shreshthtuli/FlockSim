MAKEFILE      = Makefile

first: release
install: release-install
uninstall: release-uninstall
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
MOVE          = mv -f
SUBTARGETS    =  release


release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 

Makefile: ./src/FlockSim.pro ./lib/*.prl ./lib/*.pri ./lib/conf/*.conf ./lib/features/*.prf ./lib/modules/*.pri ./lib/plugins/*.prl ./lib/win32/*.prf
make_first: release-make_first debug-make_first  FORCE
all: release-all debug-all  FORCE
clean: release-clean debug-clean  FORCE
distclean: release-distclean debug-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) "./flocksim_plugin_import.cpp" .qmake.stash

check: first

benchmark: first
FORCE:

$(MAKEFILE).Release: Makefile
