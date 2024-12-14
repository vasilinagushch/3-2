#define _CRT_SECURE_NO_WARNINGS
#include "Puzzle.h"
#include "Player.h"
#include <cstring>

#include "Player.h" // ��������� ������������� ����� Player.h

// ����������� �� ���������
Player::Player() : score(0) {
    strcpy(name, "");
}

// ����������� � ������ ������
Player::Player(const char* playerName) : score(0) {
    strcpy(name, playerName);
}

// ����� ��� ��������� ����� ������
const char* Player::getName() const {
    return name;
}

// ����� ��� ��������� ����� ������
int Player::getScore() const {
    return score;
}

// ����� ��� ���������� �����
void Player::incrementScore() {
    score++;
}

// ����� ��� ������ �����
void Player::resetScore() {
    score = 0;
}

// ����� ��� ��������� �����
void Player::setName(const char* playerName) {
    strcpy(name, playerName);
}