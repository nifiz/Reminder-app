target = test
compiler = gcc
source_files = main.c parser.c enums.c
headers = headers/

$(target): src/main.c src/parser.c src/enums.c
	$(compiler) src/main.c src/parser.c src/enums.c -o $(target) -Iheaders
 
clean: 
	del $(target).exe

run:
	./$(target)