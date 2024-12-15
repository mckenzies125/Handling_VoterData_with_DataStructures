COURSE = cs310
SEMESTER = fall2024
CP_NUMBER = 4
LASTNAME = Skrastins
GITUSERID = mckenzies125
EXE = voting

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = ../CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

CC = g++
FLAGS = -Wall -Wextra -g -std=c++20

all: run_trisha

run_trisha: voting.o Trisha.o Voter.o BST.o MaxHeap.o LinkedListVector.o
	$(CC) $(FLAGS) voting.o Trisha.o Voter.o BST.o MaxHeap.o LinkedListVector.o -o run_trisha

Voter.o: Voter.h Voter.cpp
	$(CC) $(FLAGS) -c Voter.cpp

voting.o: voting.cpp Trisha.h
	$(CC) $(FLAGS) -c voting.cpp

Trisha.o: BST.h LinkedListVector.h MaxHeap.h Voter.h Trisha.cpp Trisha.h #might need .o of other files
	$(CC) $(FLAGS) -c Trisha.cpp

BST.o: BST.h BST.cpp Voter.h Trisha.h MaxHeap.h
	$(CC) $(FLAGS) -c BST.cpp

MaxHeap.o: MaxHeap.h MaxHeap.cpp BST.h
	$(CC) $(FLAGS) -c MaxHeap.cpp

LinkedListVector.o: LinkedListVector.h LinkedListVector.cpp BST.h
	$(CC) $(FLAGS) -c LinkedListVector.cpp

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)
	@echo "Tarred and gzipped file is in the directory one level up"
	@echo $(TARFILE)".gz"

clean:
	rm -f *.o run_trisha
