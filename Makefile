OBJ=json_test
$(OBJ):
	@gcc cJSON.c json-c_test.c -lm -o $(OBJ)
clean:
	@rm -rf *.o  *~ $(OBJ)
		
