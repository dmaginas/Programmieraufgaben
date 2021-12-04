// AbundantOddNumbers.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

std::vector<int> divisors(int n) {
    std::vector<int> divs{ 1 };
    std::vector<int> divs2;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int j = n / i;
            divs.push_back(i);
            if (i != j) {
                divs2.push_back(j);
            }
        }
    }
    std::copy(divs2.crbegin(), divs2.crend(), std::back_inserter(divs));

    return divs;
}

int sum(const std::vector<int>& divs) {
    return std::accumulate(divs.cbegin(), divs.cend(), 0);
}

std::string sumStr(const std::vector<int>& divs) {
    auto it = divs.cbegin();
    auto end = divs.cend();
    std::stringstream ss;

    if (it != end) {
        ss << *it;
        it = std::next(it);
    }
    while (it != end) {
        ss << " + " << *it;
        it = std::next(it);
    }

    return ss.str();
}

int abundantOdd(int searchFrom, int countFrom, int countTo, bool printOne) {
    int count = countFrom;
    int n = searchFrom;
    for (; count < countTo; n += 2) {
        auto divs = divisors(n);
        int tot = sum(divs);
        if (tot > n) {
            count++;
            if (printOne && count < countTo) {
                continue;
            }
            auto s = sumStr(divs);
            if (printOne) {
                printf("%d < %s = %d\n", n, s.c_str(), tot);
            }
            else {
                printf("%2d. %5d < %s = %d\n", count, n, s.c_str(), tot);
            }
        }
    }
    return n;
}

int main() {
    using namespace std;

    const int max = 25;
    cout << "The first " << max << " abundant odd numbers are:\n";
    int n = abundantOdd(1, 0, 25, false);

    cout << "\nThe one thousandth abundant odd number is:\n";
    abundantOdd(n, 25, 1000, true);

    cout << "\nThe first abundant odd number above one billion is:\n";
    abundantOdd(1e9 + 1, 0, 1, true);

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
