MODULES := blinky

build: $(addprefix build_, $(MODULES))

test: $(addprefix test_, $(MODULES))

build_%:
	mkdir -p ./build
	verilator -Wall -cc src/$(lastword $(subst _, ,$@)).v \
	  --Mdir ./build/$(lastword $(subst _, ,$@)) \
		-y src/ --exe ../../test/$(lastword $(subst _, ,$@)).cpp -CFLAGS "-std=c++11" \
		-o test
	$(MAKE) -C build/$(lastword $(subst _, ,$@)) -f V$(lastword $(subst _, ,$@)).mk

test_%:
		./build/$(lastword $(subst _, ,$@))/test

default: build

clean:
	rm -rf build
