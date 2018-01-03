MODULES := blinky

blinky_files := blinky.v ../../../common/util.cpp

build: $(addprefix build_, $(MODULES))

simulate: $(addprefix simulate_, $(MODULES))

test: $(addprefix test_, $(MODULES))

build_%:
	mkdir -p ./build/$(lastword $(subst _, ,$@))/test/
	verilator -Wall -cc src/$($(lastword $(subst _, ,$@))_files) \
	  --Mdir ./build/$(lastword $(subst _, ,$@))/test \
		-y src/ --exe ../../test/$(lastword $(subst _, ,$@)).cpp \
		-CFLAGS "-std=c++11 -I../../../../common" \
		-o run
	$(MAKE) -C build/$(lastword $(subst _, ,$@))/test -f V$(lastword $(subst _, ,$@)).mk

	mkdir -p ./build/$(lastword $(subst _, ,$@))/simulator/
	verilator -Wall -cc src/$($(lastword $(subst _, ,$@))_files) \
	  --Mdir ./build/$(lastword $(subst _, ,$@))/simulator \
		-y src/ --exe ../../simulator/$(lastword $(subst _, ,$@)).cpp \
		-CFLAGS "-std=c++11 -I../../../../common" -LDFLAGS "-lncurses" \
		-o run
	$(MAKE) -C build/$(lastword $(subst _, ,$@))/simulator -f V$(lastword $(subst _, ,$@)).mk

simulate_%:
		./build/$(lastword $(subst _, ,$@))/simulator/run

test_%:
		./build/$(lastword $(subst _, ,$@))/test/run

default: build

clean:
	rm -rf build
