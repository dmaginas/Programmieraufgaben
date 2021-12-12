// PolymorphicCopy.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

class T
{
public:
    virtual void identify() { std::cout << "I am a genuine T" << std::endl; }
    virtual T* clone() { return new T(*this); }
    virtual ~T() {}
};

class S : public T
{
public:
    virtual void identify() { std::cout << "I am an S" << std::endl; }
    virtual S* clone() { return new S(*this); }
};

class X // the class of the object which contains a T or S
{
public:
    // by getting the object through a pointer to T, X cannot know if it's an S or a T
    X(T* t) : member(t) {}

    // copy constructor
    X(X const& other) : member(other.member->clone()) {}

    // copy assignment operator
    X& operator=(X const& other)
    {
        T* new_member = other.member->clone();
        delete member;
        member = new_member;
    }

    // destructor
    ~X() { delete member; }

    // check what sort of object it contains
    void identify_member() { member->identify(); }

private:
    T* member;
};

int main()
{
    X original(new S);      // construct an X and give it an S,
    X copy = original;      // copy it,
    copy.identify_member(); // and check what type of member it contains
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
