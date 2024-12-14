#ifndef PLAYER_H
#define PLAYER_H

#include <cstring>  // Для использования strcpy
#define MAX_OPTION_LENGTH 100 // Определите MAX_OPTION_LENGTH для длины имени игрока

class Player {
private:
    char name[MAX_OPTION_LENGTH];
    int score;

public:
    Player(); // Конструктор по умолчанию
    Player(const char* playerName); // Конструктор с параметром
    const char* getName() const; // Метод для получения имени
    int getScore() const; // Метод для получения счета
    void incrementScore(); // Метод для увеличения счета
    void resetScore(); // Метод для сброса счета
    void setName(const char* playerName); // Метод для установки имени
};

#endif // PLAYER_H