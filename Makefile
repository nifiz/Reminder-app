target = test
compiler = gcc
source_files = main.c parser.c enums.c commands.c parameter_loaders.c
source_files_dir = src/
headers_dir = headers
source_files_formatted = $(addprefix $(source_files_dir), $(source_files)) 

$(target): $(source_files_formatted)
	$(compiler) $(source_files_formatted) -o $(target) -I$(headers_dir) -lc
 
clean: 
	del $(target).exe

run:
	./$(target)