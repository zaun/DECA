MODULES := blinky

blinky_files := blinky.v ../../../common/util.cpp

build: $(addprefix build_, $(MODULES))

test: $(addprefix test_, $(MODULES))

build_%:
	mkdir -p ./build
	verilator -Wall -cc src/$($(lastword $(subst _, ,$@))_files) \
	  --Mdir ./build/$(lastword $(subst _, ,$@)) \
		-y src/ --exe ../../test/$(lastword $(subst _, ,$@)).cpp \
		-CFLAGS "-std=c++11 -I../../../common" \
		-o test
	$(MAKE) -C build/$(lastword $(subst _, ,$@)) -f V$(lastword $(subst _, ,$@)).mk

test_%:
		./build/$(lastword $(subst _, ,$@))/test

default: build

clean:
	rm -rf build
