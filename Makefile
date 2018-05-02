CC=gcc
CFLAGS=-Wall -g
all: calculatrice jeu

jeu: jeu.o terrains.o regles.o
	$(CC) $(CFLAGS) -o jeu $^

calculatrice: analyse_syntaxique.o analyse_lexicale.o  lecture_caracteres.o  ast_construction.o ast_parcours.o calculatrice.o table_des_symboles.o
	$(CC) $(CFLAGS) -o calculatrice analyse_syntaxique.o analyse_lexicale.o  lecture_caracteres.o ast_construction.o ast_parcours.o calculatrice.o table_des_symboles.o

regles.o: regles.c regles.h
	$(CC) $(CFLAGS) -c regles.c

terrains.o: terrains.c terrains.h
	$(CC) $(CFLAGS) -c terrains.c

jeu.o: jeu.c 
	$(CC) $(CFLAGS) -c jeu.c

table_des_symboles.o: table_des_symboles.c table_des_symboles.h 
	$(CC) $(CFLAGS) -c table_des_symboles.c

analyse_syntaxique.o: analyse_syntaxique.c analyse_syntaxique.h analyse_lexicale.h ast_construction.h ast_parcours.h table_des_symboles.h
	$(CC) $(CFLAGS) -c analyse_syntaxique.c

analyse_lexicale.o: analyse_lexicale.c analyse_lexicale.h lecture_caracteres.h
	$(CC) $(CFLAGS) -c analyse_lexicale.c

lecture_caracteres.o: lecture_caracteres.h lecture_caracteres.c
	$(CC) $(CFLAGS) -c lecture_caracteres.c

ast_construction.o: ast_construction.c ast_construction.h type_ast.h
	$(CC) $(CFLAGS) -c ast_construction.c

ast_parcours.o: ast_parcours.c ast_parcours.h type_ast.h
	$(CC) $(CFLAGS) -c ast_parcours.c

calculatrice.o: calculatrice.c analyse_syntaxique.h
	$(CC) $(CFLAGS) -c calculatrice.c

clean:
	rm -f  calculatrice *.o jeu


