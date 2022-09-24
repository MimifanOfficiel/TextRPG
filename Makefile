rpg.exe : rpg.o browseFiles.o profileCreation.o filesCreation.o ustrings.o
	g++ -Wall -o rpg.exe rpg.o browseFiles.o profileCreation.o filesCreation.o
	mingw32-make clean

rpg.o : rpg.cpp
	g++ --std=c++17 -Wall -c rpg.cpp

ustrings.o : ./Utils/strings/ustrings.cpp ./Utils/strings/ustrings.hpp
	g++ --std=c++17 -Wall -c ./Utils/strings/ustrings.cpp

browseFiles.o : ./browseFiles/browseFiles.cpp ./browseFiles/browseFiles.hpp
	g++ --std=c++17 -Wall -c ./browseFiles/browseFiles.cpp

profileCreation.o : ../../Utils/strings/ustrings.o ./gameCreation/profileCreation/profileCreation.cpp ./gameCreation/profileCreation/profileCreation.hpp
	g++ --std=c++17 -Wall -c ./gameCreation/profileCreation/profileCreation.cpp

filesCreation.o : ./gameCreation/filesCreation/filesCreation.cpp ./gameCreation/filesCreation/filesCreation.hpp
	g++ --std=c++17 -Wall -c ./gameCreation/filesCreation/filesCreation.cpp

clean :
	del -f *.o