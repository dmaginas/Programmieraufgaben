// Tokenize_a_string_with_escaping.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

vector<string> tokenize(const string& input, char seperator, char escape) {
    vector<string> output;
    string token;

    bool inEsc = false;
    for (char ch : input) {
        if (inEsc) {
            inEsc = false;
        }
        else if (ch == escape) {
            inEsc = true;
            continue;
        }
        else if (ch == seperator) {
            output.push_back(token);
            token = "";
            continue;
        }
        token += ch;
    }
    if (inEsc)
        throw new invalid_argument("Invalid terminal escape");

    output.push_back(token);
    return output;
}

int main() {
    string sample = "one^|uno||three^^^^|four^^^|^cuatro|";

    cout << sample << endl;
    cout << '[';
    for (auto t : tokenize(sample, '|', '^')) {
        cout << '"' << t << "\", ";
    }
    cout << ']' << endl;

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
