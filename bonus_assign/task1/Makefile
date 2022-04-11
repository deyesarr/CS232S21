msb.s : msb
	objdump -dSl msb >msb.s

gdb : msb
	gdb -ex "set disassemble-next-line on" -ex "break main" -ex "run" --args ./msb 14

test : msb
	./msb 14
	
msb : msb.s
	gcc -O0 -g -Wall -std=c11 -o msb msb.s
	
clean :
	-rm msb msb.s
