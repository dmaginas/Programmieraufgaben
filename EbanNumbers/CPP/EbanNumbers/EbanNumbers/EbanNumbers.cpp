// EbanNumbers.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

struct Interval {
    int start, end;
    bool print;
};

int main() {
    Interval intervals[] = {
        {2, 1000, true},
        {1000, 4000, true},
        {2, 10000, false},
        {2, 100000, false},
        {2, 1000000, false},
        {2, 10000000, false},
        {2, 100000000, false},
        {2, 1000000000, false},
    };

    for (auto intv : intervals) {
        if (intv.start == 2) {
            std::cout << "eban numbers up to and including " << intv.end << ":\n";
        }
        else {
            std::cout << "eban numbers bwteen " << intv.start << " and " << intv.end << " (inclusive):\n";
        }

        int count = 0;
        for (int i = intv.start; i <= intv.end; i += 2) {
            int b = i / 1000000000;
            int r = i % 1000000000;
            int m = r / 1000000;
            r = i % 1000000;
            int t = r / 1000;
            r %= 1000;
            if (m >= 30 && m <= 66) m %= 10;
            if (t >= 30 && t <= 66) t %= 10;
            if (r >= 30 && r <= 66) r %= 10;
            if (b == 0 || b == 2 || b == 4 || b == 6) {
                if (m == 0 || m == 2 || m == 4 || m == 6) {
                    if (t == 0 || t == 2 || t == 4 || t == 6) {
                        if (r == 0 || r == 2 || r == 4 || r == 6) {
                            if (intv.print) std::cout << i << ' ';
                            count++;
                        }
                    }
                }
            }
        }
        if (intv.print) {
            std::cout << '\n';
        }
        std::cout << "count = " << count << "\n\n";
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
