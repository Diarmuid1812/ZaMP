__start__: obj interp __plugin__
	export LD_LIBRARY_PATH="./libs"; ./interp ../opis_dzialan/opis_dzialan.cmd

obj:
	mkdir obj

__plugin__:
	cd plugin; make

CPPFLAGS=-Wall -pedantic -std=c++11 -Iinc
LDFLAGS=-Wall
ADDLIBS=-ldl -lxerces-c -lpthread

interp: obj/main.o obj/LibInterface.o obj/Configuration.o obj/XML_ReadFile.o obj/xmlinterp.o\
						obj/ServerConnection.o obj/Scene.o
	g++ ${LDFLAGS} -o interp  obj/main.o obj/LibInterface.o obj/Configuration.o obj/XML_ReadFile.o\
	                  obj/xmlinterp.o obj/ServerConnection.o  ${ADDLIBS}

obj/main.o: src/main.cpp inc/Interp4Command.hh inc/Set4Libinterfaces.hh inc/XML_ReadFile.hh\
             inc/Configuration.hh inc/LibInterface.hh inc/XML_ReadFile.hh\
						 inc/xmlinterp.hh inc/ServerConnection.hh inc/Scene.hh
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/LibInterface.o: src/LibInterface.cpp inc/LibInterface.hh inc/Interp4Command.hh
	g++ -c ${CPPFLAGS} -o obj/LibInterface.o src/LibInterface.cpp

obj/Scene.o: src/Scene.cpp inc/Scene.hh inc/Scene.hh
	g++ -c ${CPPFLAGS} -o obj/Scene.o src/Scene.cpp

obj/Configuration.o: src/Configuration.cpp inc/Configuration.hh inc/MobileObj.hh
		g++ -c ${CPPFLAGS} -o obj/Configuration.o src/Configuration.cpp

obj/XML_ReadFile.o: src/XML_ReadFile.cpp inc/XML_ReadFile.hh
		g++ -c ${CPPFLAGS} -o obj/XML_ReadFile.o src/XML_ReadFile.cpp

obj/xmlinterp.o: src/xmlinterp.cpp inc/xmlinterp.hh inc/Configuration.hh
		g++ -c ${CPPFLAGS} -o obj/xmlinterp.o src/xmlinterp.cpp

obj/ServerConnection.o: src/ServerConnection.cpp inc/ServerConnection.hh inc/Scene.hh
		g++ -c ${CPPFLAGS} -o obj/ServerConnection.o src/ServerConnection.cpp

doc:
	cd dox; make

clean:
	rm -f obj/* interp core*


clean_plugin:
	cd plugin; make clean

cleanall: clean
	cd plugin; make cleanall
	cd dox; make cleanall
	rm -f libs/*
	find . -name \*~ -print -exec rm {} \;

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  doc   - generuje dokumentację programu"
	@echo "  clean    - usuwa produkty kompilacji oraz program"
	@echo "  clean_plugin - usuwa plugin"
	@echo "  cleanall - wykonuje wszystkie operacje dla podcelu clean oraz clean_plugin"
	@echo "             oprocz tego usuwa wszystkie kopie (pliki, ktorych nazwa "
	@echo "             konczy sie znakiem ~)."
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo
