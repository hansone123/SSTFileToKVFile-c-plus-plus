include config.mk

SRC := $(wildcard $(TOP)/src/*.cc)
HDR := $(wildcard $(TOP)/src/*.h)

OBJ := $(patsubst %.cc,%.o,$(wildcard $(TOP)/src/*.cc))
OBJ := $(patsubst $(TOP)/src/%, %,$(OBJ))
	
TEST := $(patsubst %.cc,%$(EXE),$(wildcard $(TOP)/test/*.cc))
TEST := $(patsubst $(TOP)/test/%, %,$(TEST))

all: check liblptc.a test 
	
check:
	echo 'HDR: $(HDR)'
	echo 'SRC: $(SRC)'
	echo 'OBJ: $(OBJ)'
	echo 'TEST: $(TEST)'
	
liblptc.a: $(OBJ)
	$(AR) liblptc.a $(TOP)/obj/*.o
	$(RANLIB) liblptc.a
%.o: $(TOP)/src/%.cc
	g++ -o $(TOP)/obj/$@ -c $<


test: $(TEST)
	
main$(EXE):
	g++ -o $(TOP)/test/main$(EXE) $(TOP)/test/main.cc $(HDR) liblptc.a $(LIBPTHREAD) $(LIBLEVELDB)
#%$(EXE): $(TOP)/test/%.cc
#	g++ -o $(TOP)/test/$@ -c $< $(HDR) liblptc.a $(LIBPTHREAD) $(LIBLEVELDB)
testKVProvider$(EXE):
	g++ -o $(TOP)/test/testKVProvider$(EXE) $(TOP)/test/testKVProvider.cc $(HDR) liblptc.a $(LIBPTHREAD) $(LIBLEVELDB)
testKVToCSV$(EXE):
	g++ -o $(TOP)/test/testKVToCSV$(EXE) $(TOP)/test/testKVToCSV.cc $(HDR) liblptc.a $(LIBPTHREAD) $(LIBLEVELDB)
testVarint$(EXE):
	g++ -o $(TOP)/test/testVarint$(EXE) $(TOP)/test/testVarint.cc $(HDR) liblptc.a $(LIBPTHREAD) $(LIBLEVELDB)

clean:
	rm $(TOP)/test/*$(EXE)
	rm $(TOP)/obj/*
testcmd:
	echo $(OBJ)