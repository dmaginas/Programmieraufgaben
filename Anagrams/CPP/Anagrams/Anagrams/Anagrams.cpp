// Anagrams.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>

bool is_deranged(const std::string& left, const std::string& right)
{
    return (left.size() == right.size()) &&
        (std::inner_product(left.begin(), left.end(), right.begin(), 0, std::plus<int>(), std::equal_to<char>()) == 0);
}

int main()
{
    std::ifstream input("d:\\Develop\\VSProjects\\Programmieraufgaben\\Anagrams\\unixdict.txt");
    if (!input) {
        std::cerr << "can't open input file\n";
        return EXIT_FAILURE;
    }

    typedef std::set<std::string> WordList;
    typedef std::map<std::string, WordList> AnagraMap;
    AnagraMap anagrams;

    std::pair<std::string, std::string> result;
    size_t longest = 0;

    for (std::string value; input >> value; /**/) {
        std::string key(value);
        std::sort(key.begin(), key.end());

        if (longest < value.length()) { // is it a long candidate?
            if (0 < anagrams.count(key)) { // is it an anagram?
                for (const auto& prior : anagrams[key]) {
                    if (is_deranged(prior, value)) { // are they deranged?
                        result = std::make_pair(prior, value);
                        longest = value.length();
                    }
                }
            }
        }
        anagrams[key].insert(value);
    }

    std::cout << result.first << ' ' << result.second << '\n';
    return EXIT_SUCCESS;
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
