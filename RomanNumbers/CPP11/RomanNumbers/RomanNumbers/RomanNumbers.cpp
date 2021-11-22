// RomanNumbers.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>

std::string to_roman(int x) {
    if (x <= 0)
        return "Negative or zero!";
    auto roman_digit = [](char one, char five, char ten, int x) {
        if (x <= 3)
            return std::string().assign(x, one);
        if (x <= 5)
            return std::string().assign(5 - x, one) + five;
        if (x <= 8)
            return five + std::string().assign(x - 5, one);
        return std::string().assign(10 - x, one) + ten;
    };
    if (x >= 1000)
        return x - 1000 > 0 ? "M" + to_roman(x - 1000) : "M";
    if (x >= 100) {
        auto s = roman_digit('C', 'D', 'M', x / 100);
        return x % 100 > 0 ? s + to_roman(x % 100) : s;
    }
    if (x >= 10) {
        auto s = roman_digit('X', 'L', 'C', x / 10);
        return x % 10 > 0 ? s + to_roman(x % 10) : s;
    }
    return roman_digit('I', 'V', 'X', x);
}

int main() {
    for (int i = 0; i < 2022; i++)
        std::cout << i << " --> " << to_roman(i) << std::endl;
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
