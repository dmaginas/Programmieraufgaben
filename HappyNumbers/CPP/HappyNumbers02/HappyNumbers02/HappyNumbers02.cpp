// HappyNumbers02.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

unsigned int happy_iteration(unsigned int n)
{
    unsigned int result = 0;
    while (n > 0)
    {
        unsigned int lastdig = n % 10;
        result += lastdig * lastdig;
        n /= 10;
    }
    return result;
}

bool is_happy(unsigned int n)
{
    unsigned int n2 = happy_iteration(n);
    while (n != n2)
    {
        n = happy_iteration(n);
        n2 = happy_iteration(happy_iteration(n2));
    }
    return n == 1;
}

#include <iostream>

int main()
{
    unsigned int current_number = 1;

    unsigned int happy_count = 0;
    while (happy_count != 8)
    {
        if (is_happy(current_number))
        {
            std::cout << current_number << " ";
            ++happy_count;
        }
        ++current_number;
    }
    std::cout << std::endl;
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
