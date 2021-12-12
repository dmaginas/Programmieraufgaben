// HappyNumbers01.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <map>
#include <set>

bool happy(int number) {
    static std::map<int, bool> cache;

    std::set<int> cycle;
    while (number != 1 && !cycle.count(number)) {
        if (cache.count(number)) {
            number = cache[number] ? 1 : 0;
            break;
        }
        cycle.insert(number);
        int newnumber = 0;
        while (number > 0) {
            int digit = number % 10;
            newnumber += digit * digit;
            number /= 10;
        }
        number = newnumber;
    }
    bool happiness = number == 1;
    for (std::set<int>::const_iterator it = cycle.begin();
        it != cycle.end(); it++)
        cache[*it] = happiness;
    return happiness;
}

#include <iostream>

int main() {
    for (int i = 1; i < 50; i++)
        if (happy(i))
            std::cout << i << std::endl;
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
