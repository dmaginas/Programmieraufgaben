// ReadConfigFile.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <fstream>
#include <vector>
#include <algorithm>

struct confi {
	std::string fullname;
	std::string favouritefruit;
	bool needspeeling;
	bool seedsremoved;
	std::vector<std::string> otherfamily;
};

void read_config(std::ifstream& in, confi& out) {
	in.open("Config.txt");
	std::string str;
	out.needspeeling = false;
	out.seedsremoved = false;
	while (!in.eof()) {
		while (getline(in, str)) {
			std::string::size_type begin = str.find_first_not_of(" \f\t\v");
			//Skips blank lines
			if (begin == std::string::npos)
				continue;
			//Skips #
			if (std::string("#").find(str[begin]) != std::string::npos)
				continue;
			std::string firstWord;
			try {
				firstWord = str.substr(0, str.find(" "));
			}
			catch (std::exception& e) {
				firstWord = str.erase(str.find_first_of(" "), str.find_first_not_of(" "));
			}
			std::transform(firstWord.begin(), firstWord.end(), firstWord.begin(), ::toupper);
			if (firstWord == "FULLNAME")
				out.fullname = str.substr(str.find(" ") + 1, str.length());
			if (firstWord == "FAVOURITEFRUIT")
				out.favouritefruit = str.substr(str.find(" ") + 1, str.length());
			if (firstWord == "NEEDSPEELING")
				out.needspeeling = true;
			if (firstWord == "SEEDSREMOVED")
				out.seedsremoved = true;
			if (firstWord == "OTHERFAMILY") {
				size_t found = str.find(",");
				if (found != std::string::npos) {
					out.otherfamily.push_back(str.substr(str.find_first_of(" ") + 1, found - str.find_first_of(" ") - 1));
					out.otherfamily.push_back(str.substr(found + 2, str.length()));
				}
			}

		}
	}
	std::cout << "Full Name: " << out.fullname << std::endl;
	std::cout << "Favourite Fruit: " << out.favouritefruit << std::endl;
	std::cout << "Needs peeling?: ";
	if (out.needspeeling == true)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	std::cout << "Seeds removed?: ";
	if (out.seedsremoved == true)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	std::cout << "Other family members: " << out.otherfamily[0] << ", " << out.otherfamily[1] << std::endl;
}
int main() {
	std::ifstream inp;
	confi outp;
	read_config(inp, outp);
}
// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
