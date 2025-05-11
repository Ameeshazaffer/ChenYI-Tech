# Variables
CC = gcc
CFLAGS = -Wall -g
OBJETS = main.o animal.o refuge.o
EXEC = chenil

# Règle par défaut (compiler le projet)
all: $(EXEC)

# Lier les objets pour créer l'exécutable
$(EXEC): $(OBJETS)
	$(CC) $(OBJETS) -o $(EXEC)

# Compilation de main.c
main.o: main.c animal.h refuge.h
	$(CC) $(CFLAGS) -c main.c

# Compilation de animal.c
animal.o: animal.c animal.h refuge.h
	$(CC) $(CFLAGS) -c animal.c

# Compilation de refuge.c
refuge.o: refuge.c animal.h refuge.h
	$(CC) $(CFLAGS) -c refuge.c

# Nettoyer les fichiers objets, l'exécutable, et les données
fclean:
	rm -f $(OBJETS) $(EXEC)
	rm -f refuge.txt
	touch refuge.txt

# Recompiler entièrement
re: fclean all
