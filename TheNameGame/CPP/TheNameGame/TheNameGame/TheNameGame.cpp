// TheNameGame.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

static void printVerse(const std::string& name) {
    std::string x = name;
    std::transform(x.begin(), x.end(), x.begin(), ::tolower);
    x[0] = toupper(x[0]);

    std::string y;
    switch (x[0]) {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        y = x;
        std::transform(y.begin(), y.end(), y.begin(), ::tolower);
        break;
    default:
        y = x.substr(1);
        break;
    }

    std::string b("b" + y);
    std::string f("f" + y);
    std::string m("m" + y);

    switch (x[0]) {
    case 'B':
        b = y;
        break;
    case 'F':
        f = y;
        break;
    case 'M':
        m = y;
        break;
    default:
        break;
    }

    printf("%s, %s, bo-%s\n", x.c_str(), x.c_str(), b.c_str());
    printf("Banana-fana fo-%s\n", f.c_str());
    printf("Fee-fi-mo-%s\n", m.c_str());
    printf("%s!\n\n", x.c_str());
}

int main() {
    using namespace std;

    vector<string> nameList{ "Gary", "Earl", "Billy", "Felix", "Mary", "Steve", "Dimos"};
    for (auto& name : nameList) {
        printVerse(name);
    }

    return 0;
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
