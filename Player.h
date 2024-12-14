#ifndef PLAYER_H
#define PLAYER_H

#include <cstring>  // ��� ������������� strcpy
#define MAX_OPTION_LENGTH 100 // ���������� MAX_OPTION_LENGTH ��� ����� ����� ������

class Player {
private:
    char name[MAX_OPTION_LENGTH];
    int score;

public:
    Player(); // ����������� �� ���������
    Player(const char* playerName); // ����������� � ����������
    const char* getName() const; // ����� ��� ��������� �����
    int getScore() const; // ����� ��� ��������� �����
    void incrementScore(); // ����� ��� ���������� �����
    void resetScore(); // ����� ��� ������ �����
    void setName(const char* playerName); // ����� ��� ��������� �����
};

#endif // PLAYER_H