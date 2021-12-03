// MorseCode.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string.h>
#include <string>

using namespace std;
int main(int argc, char* argv[])
{
    string inpt;
    char ascii[28] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ", lwcAscii[28] = " abcdefghijklmnopqrstuvwxyz";
    string morse[27] = { "  ", ".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ", ".... ", ".. ", ".--- ", "-.- ", ".-.. ", "-- ", "-. ", "--- ", ".--.", "--.- ", ".-. ", "... ", "- ", "..- ", "...- ", ".-- ", "-..- ", "-.-- ", "--.. " };
    string outpt;
    getline(cin, inpt);
    int xx = 0;
    int size = inpt.length();
    cout << "Length:" << size << endl;

    xx = 0;
    while (xx < inpt.length())
    {
        int x = 0;
        bool working = false;
        while (!working)
        {
            if (ascii[x] != inpt[xx] && lwcAscii[x] != inpt[xx])
            {
                x++;
            }
            else
            {
                working = !working;
            }
        }

        cout << morse[x];
        outpt = outpt + morse[x];
        xx++;
    }

    xx = 0;
    while (xx < outpt.length() + 1)
    {
        if (outpt[xx] == '.')
        {
            Beep(1000, 250);
        }
        else
        {
            if (outpt[xx] == '-')
            {
                Beep(1000, 500);
            }
            else
            {
                if (outpt[xx] == ' ')
                {
                    Sleep(500);
                }
            }
        }
        xx++;
    }
    system("PAUSE");
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
