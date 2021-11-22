// WordWrap.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <sstream>
#include <string>

const char* text =
{
    "In olden times when wishing still helped one, there lived a king "
    "whose daughters were all beautiful, but the youngest was so beautiful "
    "that the sun itself, which has seen so much, was astonished whenever "
    "it shone in her face.  Close by the king's castle lay a great dark "
    "forest, and under an old lime tree in the forest was a well, and when "
    "the day was very warm, the king's child went out into the forest and "
    "sat down by the side of the cool fountain, and when she was bored she "
    "took a golden ball, and threw it up on high and caught it, and this "
    "ball was her favorite plaything."
};

std::string wrap(const char* text, size_t line_length = 72)
{
    std::istringstream words(text);
    std::ostringstream wrapped;
    std::string word;

    if (words >> word) {
        wrapped << word;
        size_t space_left = line_length - word.length();
        while (words >> word) {
            if (space_left < word.length() + 1) {
                wrapped << '\n' << word;
                space_left = line_length - word.length();
            }
            else {
                wrapped << ' ' << word;
                space_left -= word.length() + 1;
            }
        }
    }
    return wrapped.str();
}

int main()
{
    std::cout << "Wrapped at 72:\n" << wrap(text) << "\n\n";
    std::cout << "Wrapped at 80:\n" << wrap(text, 80) << "\n";
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
