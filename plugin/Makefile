__start__: obj ../libs/libPolecenie_Oko.so ../libs/libPolecenie_Usta.so ../libs/libPolecenie_Brew.so
	@echo "  Tworzenie wtyczki zakonczone."
	@echo

obj:
	mkdir obj

CPPFLAGS=-Wall -fPIC -pedantic -Iinc -I../inc -std=c++11
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

../libs/libPolecenie_Brew.so: obj/command4Brow.o
	g++ ${LDFLAGS} -o ../libs/libPolecenie_Brew.so obj/command4Brow.o
	@echo
	@echo "  Wtyczka dla polecenia 'Brew' zostala utworzona."
	@echo

obj/command4Eye.o: src/command4Eye.cpp ../inc/command.h\
                        inc/command4Eye.h ../inc/robotfaceInterface.h
	g++ -c ${CPPFLAGS} -o obj/command4Eye.o src/command4Eye.cpp

obj/command4Mouth.o: src/command4Mouth.cpp ../inc/command.h\
                        inc/command4Mouth.h ../inc/robotfaceInterface.h
	g++ -c ${CPPFLAGS} -o obj/command4Mouth.o src/command4Mouth.cpp

obj/command4Brow.o: src/command4Brow.cpp ../inc/command.h\
                        inc/command4Brow.h ../inc/robotfaceInterface.h
	g++ -c ${CPPFLAGS} -o obj/command4Brow.o src/command4Brow.cpp

clean:
	rm -f obj/*

cleanall: clean
	find . -name \*~ -print -exec rm {} \;
