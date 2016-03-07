include config.mk

SRC := $(wildcard $(TOP)/src/*.cc)
HDR := $(wildcard $(TOP)/src/*.h)

OBJ := $(patsubst %.cc,%.o,$(wildcard $(TOP)/src/*.cc))
OBJ := $(patsubst $(TOP)/src/%, %,$(OBJ))
	
TEST := $(patsubst %.cc,%$(EXE),$(wildcard $(TOP)/test/*.cc))
TEST := $(patsubst $(TOP)/test/%, %,$(TEST))

all: check libSstToKV.a test 
	
check:
	echo 'HDR: $(HDR)'
	echo 'SRC: $(SRC)'
	echo 'OBJ: $(OBJ)'
	echo 'TEST: $(TEST)'
	
libSstToKV.a: $(OBJ)
	$(AR) libSstToKV.a $(TOP)/obj/*.o
	$(RANLIB) libSstToKV.a
%.o: $(TOP)/src/%.cc
	g++ -o $(TOP)/obj/$@ -c $<


test: $(TEST)
	
testFileObserver$(EXE):
	g++ -o $(TOP)/test/testFileObserver$(EXE) $(TOP)/test/testFileObserver.cc $(HDR) libSstToKV.a $(LIBPTHREAD) $(LIBLEVELDB)
#%$(EXE): $(TOP)/test/%.cc
#	g++ -o $(TOP)/test/$@ -c $< $(HDR) libSstToKV.a $(LIBPTHREAD) $(LIBLEVELDB)
testKVProvider$(EXE):
	g++ -o $(TOP)/test/testKVProvider$(EXE) $(TOP)/test/testKVProvider.cc $(HDR) libSstToKV.a $(LIBPTHREAD) $(LIBLEVELDB)
testKVToCSV$(EXE):
	g++ -o $(TOP)/test/testKVToCSV$(EXE) $(TOP)/test/testKVToCSV.cc $(HDR) libSstToKV.a $(LIBPTHREAD) $(LIBLEVELDB)
testVarint$(EXE):
	g++ -o $(TOP)/test/testVarint$(EXE) $(TOP)/test/testVarint.cc $(HDR) libSstToKV.a $(LIBPTHREAD) $(LIBLEVELDB)

clean:
	rm $(TOP)/test/*$(EXE)
	rm $(TOP)/obj/*
testcmd:
	echo $(OBJ)