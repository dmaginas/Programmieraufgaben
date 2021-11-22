// ConwaysGameOfLife.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#define HEIGHT 4
#define WIDTH 4

struct Shape {
public:
    char xCoord;
    char yCoord;
    char height;
    char width;
    char** figure;
};

struct Glider : public Shape {
    static const char GLIDER_SIZE = 3;
    Glider(char x, char y);
    ~Glider();
};

struct Blinker : public Shape {
    static const char BLINKER_HEIGHT = 3;
    static const char BLINKER_WIDTH = 1;
    Blinker(char x, char y);
    ~Blinker();
};

class GameOfLife {
public:
    GameOfLife(Shape sh);
    void print();
    void update();
    char getState(char state, char xCoord, char yCoord, bool toggle);
    void iterate(unsigned int iterations);
private:
    char world[HEIGHT][WIDTH];
    char otherWorld[HEIGHT][WIDTH];
    bool toggle;
    Shape shape;
};

GameOfLife::GameOfLife(Shape sh) :
    shape(sh),
    toggle(true)
{
    for (char i = 0; i < HEIGHT; i++) {
        for (char j = 0; j < WIDTH; j++) {
            world[i][j] = '.';
        }
    }
    for (char i = shape.yCoord; i - shape.yCoord < shape.height; i++) {
        for (char j = shape.xCoord; j - shape.xCoord < shape.width; j++) {
            if (i < HEIGHT && j < WIDTH) {
                world[i][j] =
                    shape.figure[i - shape.yCoord][j - shape.xCoord];
            }
        }
    }
}

void GameOfLife::print() {
    if (toggle) {
        for (char i = 0; i < HEIGHT; i++) {
            for (char j = 0; j < WIDTH; j++) {
                std::cout << world[i][j];
            }
            std::cout << std::endl;
        }
    }
    else {
        for (char i = 0; i < HEIGHT; i++) {
            for (char j = 0; j < WIDTH; j++) {
                std::cout << otherWorld[i][j];
            }
            std::cout << std::endl;
        }
    }
    for (char i = 0; i < WIDTH; i++) {
        std::cout << '=';
    }
    std::cout << std::endl;
}

void GameOfLife::update() {
    if (toggle) {
        for (char i = 0; i < HEIGHT; i++) {
            for (char j = 0; j < WIDTH; j++) {
                otherWorld[i][j] =
                    GameOfLife::getState(world[i][j], i, j, toggle);
            }
        }
        toggle = !toggle;
    }
    else {
        for (char i = 0; i < HEIGHT; i++) {
            for (char j = 0; j < WIDTH; j++) {
                world[i][j] =
                    GameOfLife::getState(otherWorld[i][j], i, j, toggle);
            }
        }
        toggle = !toggle;
    }
}

char GameOfLife::getState(char state, char yCoord, char xCoord, bool toggle) {
    char neighbors = 0;
    if (toggle) {
        for (char i = yCoord - 1; i <= yCoord + 1; i++) {
            for (char j = xCoord - 1; j <= xCoord + 1; j++) {
                if (i == yCoord && j == xCoord) {
                    continue;
                }
                if (i > -1 && i < HEIGHT && j > -1 && j < WIDTH) {
                    if (world[i][j] == 'X') {
                        neighbors++;
                    }
                }
            }
        }
    }
    else {
        for (char i = yCoord - 1; i <= yCoord + 1; i++) {
            for (char j = xCoord - 1; j <= xCoord + 1; j++) {
                if (i == yCoord && j == xCoord) {
                    continue;
                }
                if (i > -1 && i < HEIGHT && j > -1 && j < WIDTH) {
                    if (otherWorld[i][j] == 'X') {
                        neighbors++;
                    }
                }
            }
        }
    }
    if (state == 'X') {
        return (neighbors > 1 && neighbors < 4) ? 'X' : '.';
    }
    else {
        return (neighbors == 3) ? 'X' : '.';
    }
}

void GameOfLife::iterate(unsigned int iterations) {
    for (int i = 0; i < iterations; i++) {
        print();
        update();
    }
}

Glider::Glider(char x, char y) {
    xCoord = x;
    yCoord = y;
    height = GLIDER_SIZE;
    width = GLIDER_SIZE;
    figure = new char* [GLIDER_SIZE];
    for (char i = 0; i < GLIDER_SIZE; i++) {
        figure[i] = new char[GLIDER_SIZE];
    }
    for (char i = 0; i < GLIDER_SIZE; i++) {
        for (char j = 0; j < GLIDER_SIZE; j++) {
            figure[i][j] = '.';
        }
    }
    figure[0][1] = 'X';
    figure[1][2] = 'X';
    figure[2][0] = 'X';
    figure[2][1] = 'X';
    figure[2][2] = 'X';
}

Glider::~Glider() {
    for (char i = 0; i < GLIDER_SIZE; i++) {
        delete[] figure[i];
    }
    delete[] figure;
}

Blinker::Blinker(char x, char y) {
    xCoord = x;
    yCoord = y;
    height = BLINKER_HEIGHT;
    width = BLINKER_WIDTH;
    figure = new char* [BLINKER_HEIGHT];
    for (char i = 0; i < BLINKER_HEIGHT; i++) {
        figure[i] = new char[BLINKER_WIDTH];
    }
    for (char i = 0; i < BLINKER_HEIGHT; i++) {
        for (char j = 0; j < BLINKER_WIDTH; j++) {
            figure[i][j] = 'X';
        }
    }
}

Blinker::~Blinker() {
    for (char i = 0; i < BLINKER_HEIGHT; i++) {
        delete[] figure[i];
    }
    delete[] figure;
}

int main() {
    Glider glider(0, 0);
    GameOfLife gol(glider);
    gol.iterate(5);
    Blinker blinker(1, 0);
    GameOfLife gol2(blinker);
    gol2.iterate(4);
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
