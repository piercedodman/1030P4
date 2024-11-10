#
# Makefile for P4
# COSC 1030
# Fall 2024
#


DRIVER_NAME = main
SUBMIT_NAME = submit
TIMER_NAME = ProcessTimer
RESULTS_NAME = P4ExperimentResultsTable.pdf


a.out: $(DRIVER_NAME).o $(TIMER_NAME).o Exceptions.o Resources.o
	g++ -std=c++14 $(DRIVER_NAME).o $(TIMER_NAME).o Exceptions.o Resources.o

$(DRIVER_NAME).o: $(DRIVER_NAME).cpp $(DRIVER_NAME).h LL.h $(TIMER_NAME).h Exceptions.h Resources.h
	g++ -std=c++14 -c $(DRIVER_NAME).cpp


$(TIMER_NAME).o: $(TIMER_NAME).cpp $(TIMER_NAME).h Exceptions.h
	g++ -std=c++14 -c $(TIMER_NAME).cpp

Exceptions.o: Exceptions.cpp Exceptions.h
	g++ -std=c++14 -c Exceptions.cpp

Resources.o: Resources.cpp Resources.h Exceptions.h
	g++ -std=c++14 -c Resources.cpp

.PHONY: submit clean

submit:
	rm -f $(SUBMIT_NAME).zip
	zip $(SUBMIT_NAME).zip Makefile $(DRIVER_NAME).cpp $(DRIVER_NAME).h LL.h $(TIMER_NAME).cpp $(TIMER_NAME).h Exceptions.cpp Exceptions.h Resources.cpp Resources.h $(RESULTS_NAME)

clean:
	rm -f *.o core a.out
