# **Project:** DECA

I got myself a DECA for Christmas 2017. I'm an avid programmer, I know several leanguages, and it's been my professional career for the last 25 years or so. I wanted to try something new so I'm delving into the world of FPGAs.

### Hardware

I went with the [DECA](https://www.arrow.com/en/products/deca/arrow-development-tools) FPGA board. It seemed to have a lot for the price. Specifically I'm interested in the USB and HDMI ports but I'm going to be playing with everything as I learn.

* [Schematics](https://github.com/zaun/DECA/raw/master/documents/decaschematic.pdf)
* [User Guide](https://github.com/zaun/DECA/raw/master/documents/deca_user_manual_rev1.pdf)

### Tools

I'm on a Apple Mac. I know, I'm probably asking for a world of hurt but I'm attempting to do as much as I can without a VM.

* [Brew](https://brew.sh/) - Get it, love it. On a Mac, there is no better way to install all the apps
* [icarus-verilog](http://brewformulas.org/IcarusVerilog) - I haven't used this directly yet, but its required for other things to work
* [verilator](http://brewformulas.org/verilator) - Simulation framework used for testing and debugging

I use [Atom](https://atom.io/) as my editor. It is more than enough for my needs. I use the following packages for Atom:

* [language-verilog](https://atom.io/packages/language-verilog) - Syntax highlighting for Verilog and SystemVerilog
* [linter-verilog](https://atom.io/packages/linter-verilog) - A linter for Verilog and SystemVerilog
* [language-make](https://atom.io/packages/language-make) - Syntax highlighting for Makefiles

### Projects

Name | Description
---- | -----------
[Blinky](https://github.com/zaun/DECA/tree/master/blinky) | It's my first project, everyone should blink at least once

### My setup

Each project will have a directory under the root of this repo. It will also have a link in the above list with some status about it's project. 

Each project as a Makefile. If you don't know what a Makefile is, you don't really need to worry about the details. Just know it help make using the project a lot easier.

```
> make
```
This will build all modules in the project with verilator.

```
> make test
```
This will run all the unit tests that exist for the project. I try my best to verify these are passing before I commit. Sometimes I'm just lazy though.

```
> make clean
```
This will clean things up and remove the whole build folder
