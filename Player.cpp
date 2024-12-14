#define _CRT_SECURE_NO_WARNINGS
#include "Puzzle.h"
#include "Player.h"
#include <cstring>

#include "Player.h" // Включение заголовочного файла Player.h

// Конструктор по умолчанию
Player::Player() : score(0) {
    strcpy(name, "");
}

// Конструктор с именем игрока
Player::Player(const char* playerName) : score(0) {
    strcpy(name, playerName);
}

// Метод для получения имени игрока
const char* Player::getName() const {
    return name;
}

// Метод для получения счета игрока
int Player::getScore() const {
    return score;
}

// Метод для увеличения счета
void Player::incrementScore() {
    score++;
}

// Метод для сброса счета
void Player::resetScore() {
    score = 0;
}

// Метод для установки имени
void Player::setName(const char* playerName) {
    strcpy(name, playerName);
}