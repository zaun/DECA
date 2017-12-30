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

Code | Tests | DECA | Name | Description
---- | ----- | ---- | ---- | -----------
:white_square_button: | :white_square_button: | :white_medium_square: | [Blinky](/zaun/DECA/tree/master/blinky) | It's my first project, everyone should blink at least once

* Code -> Verilog code in progress / done
* Test -> Code has unit tests / Simulation
* DECA -> I've run the code on the DECA board
