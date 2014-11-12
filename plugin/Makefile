__start__: obj ../libs/libPolecenie_Oko.so ../libs/libPolecenie_Usta.so
	@echo "  Tworzenie wtyczki zakonczone."
	@echo

obj:
	mkdir obj

CPPFLAGS=-Wall -fPIC -pedantic -Iinc -I../inc
LDFLAGS=-Wall -shared


../libs/libPolecenie_Oko.so: obj/command4Eye.o
	g++ ${LDFLAGS} -o ../libs/libPolecenie_Oko.so obj/command4Eye.o
	@echo
	@echo "  Wtyczka dla polecenia 'Oko' zostala utworzona."
	@echo

../libs/libPolecenie_Usta.so: obj/command4Mouth.o
	g++ ${LDFLAGS} -o ../libs/libPolecenie_Usta.so obj/command4Mouth.o
	@echo
	@echo "  Wtyczka dla polecenia 'Usta' zostala utworzona."
	@echo

obj/command4Eye.o: src/command4Eye.cpp ../inc/command.h\
                        inc/command4Eye.h 
	g++ -c ${CPPFLAGS} -o obj/command4Eye.o src/command4Eye.cpp

obj/command4Mouth.o: src/command4Mouth.cpp ../inc/command.h\
                        inc/command4Mouth.h 
	g++ -c ${CPPFLAGS} -o obj/command4Mouth.o src/command4Mouth.cpp

clean:
	rm -f obj/*

cleanall: clean
	find . -name \*~ -print -exec rm {} \;
