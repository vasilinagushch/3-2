#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <locale>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Player.h"

using namespace std;

#define MAX_HINT_LENGTH 200
#define MAX_OPTION_LENGTH 100
#define MAX_PHRASE_LENGTH 100
#define MAX_PUZZLES 3
#define MAX_ATTEMPTS 3
#define MAX_PHRASES 3
#define MAX_HINTS 3

// главная функция
int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL)); // инициализация генератора случайных чисел

    Game game;

    // работа с "статической" переменной
    Player staticPlayer;
    cout << "Введите ваше имя (используя английские символы): ";
    char name[MAX_OPTION_LENGTH];
    cin >> name;
    staticPlayer = Player(name);

    // работа с динамической переменной
    Player* dynamicPlayer = new Player(staticPlayer);
    game.setPlayerName(dynamicPlayer->getName());
    game.initializePuzzles();
    game.initializePhrases();
    game.startGame();

    delete dynamicPlayer; // Освобождение памяти, выделенной для динамической переменной

    // работа с динамическим массивом объектов класса
    int numPlayers;
    cout << "Введите количество игроков: ";
    cin >> numPlayers;
    Player* players = new Player[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        cout << "Введите имя игрока " << i + 1 << ": ";
        cin >> name;
        players[i] = Player(name);
    }
    delete[] players; // освобождение памяти, выделенной для динамического массива объектов

    // работа с массивом динамических объектов класса
    Player** dynamicPlayers = new Player * [numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        dynamicPlayers[i] = new Player();
        cout << "Введите имя игрока " << i + 1 << ": ";
        cin >> name;
        dynamicPlayers[i]->setName(name); // Задаем имя игрока через метод setName
    }

    delete[] dynamicPlayers; // освобождение памяти, выделенной для массива указателей на динамические объекты

    return 0;
}