target = test
compiler = gcc
source_files = main.c enums.c parameter_loaders.c parser.c request_structs.c structs.c
source_files_dir = src/
headers_dir = headers
source_files_formatted = $(addprefix $(source_files_dir), $(source_files)) 

$(target): $(source_files_formatted)
	$(compiler) $(source_files_formatted) -o $(target) -I$(headers_dir)

clean: 
	del $(target)

run:
	./$(target)