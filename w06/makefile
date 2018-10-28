###############################################################
# Program:
#     Assignment 06, NODE
#     Brother Kirby, CS235
# Author:
#     Nathan Prestwich, Jose Paredes, and Cameron Dockstad
# Summary:
#     This program will allow the user to make a linked list
#     that will allow for the insertion and removal of items
#     in the list. We then implement the list into a sort
#     insertion function.
# The Most Difficult Part:
#     Nathan: The most difficult part was making the copy function
#     Jose: Relearning how to use pointers effectively 
#     for this assignment.
#     Cameron: Understading the concept of what needed to be done.
# Time:
#     Paired Programming: 30 min 
#     Nathan: 1hr 
#     Jose: 1hr
#     Cameron: 3.5 hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: node.h assignment06.o 
	g++ -o a.out assignment06.o  -g -std=c++11
	tar -cf assignment06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment06.o      : the driver program
#      <anything else?>
##############################################################
assignment06.o: node.h assignment06.cpp sortInsertion.h
	g++ -c assignment06.cpp -g -std=c++11
