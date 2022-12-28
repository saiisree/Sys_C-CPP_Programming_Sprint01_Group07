INC = /home/vidyalakshmi/Online_Interview_Management_System/inc
SRC = /home/vidyalakshmi/Online_Interview_Management_System/src
OBJ = /home/vidyalakshmi/Online_Interview_Management_System/obj

CFLAGS = -c -g -Wall
LFLAGS = -o
GCC = gcc
CVFLAGS = -Wall -c -g
IFLAGS = -I $(INC)

all : $(BIN)/interview 

$(OBJ)/main_menu_client.o : $(SRC)/main_menu_client.c
	$(GCC) $(CFLAGS) $(SRC)/main_menu_client.c $(IFLAGS)
	mv *.o/home/vidyalakshmi/Online_Interview_Management_System/obj

$(OBJ)/admin_def.o : $(SRC)/admin_def.c
	$(GCC) $(CFLAGS) $(SRC)/admin_def.c $(IFLAGS)
	mv *.o/home/vidyalakshmi/Online_Interview_Management_System/obj

$(OBJ)/company_def.o : $(SRC)/company_def.c
	$(GCC) $(CFLAGS) $(SRC)/company_def.c $(IFLAGS)
	mv *.o/home/vidyalakshmi/Online_Interview_Management_System/obj

$(OBJ)/applicant_def.o : $(SRC)/applicant_def.c
	$(GCC) $(CFLAGS) $(SRC)/applicant_def.c ($IFLAGS)
	mv *.o/home/vidyalakshmi/Online_Interview_Management_System/obj

$(OBJ)/validation_def.o : $(SRC)/validation_def.c
	$(GCC) $(CFLAGS) $(SRC)/validation_def.c $(IFLAGS)
	mv *.o/home/vidyalakshmi/Online_Interview_Management_System/obj


$(BIN)/interview : $(OBJ)/interview.o $(OBJ)/main_menu_client.o.o $(OBJ)/admin_def.o $(OBJ)/company_def.o $(OBJ)/applicant_def.o $(OBJ)/validation_def.o
	$(GCC) $(OBJ)/interview.o $(OBJ)/main_menu_client.o $(OBJ)/admin_def.o $(OBJ)/company_def.o $(OBJ)/applicant_def.o $(OBJ)/validation_def.o $(LFLAGS) $(BIN)/interview

clean:
	rm -f $(OBJ)/*.o $(BIN)/interview