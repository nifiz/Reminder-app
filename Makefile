target = test
compiler = gcc
source_files = main.c

$(target): src/main.c
	$(compiler) src/main.c -o $(target)
 
clean: 
	del $(target).exe