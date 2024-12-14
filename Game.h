#pragma once
// Game.h
#ifndef GAME_H
#define GAME_H 

#define MAX_PHRASES 3
#define MAX_PUZZLES 3
#define MAX_ATTEMPTS 3

#include <iostream>
#include <cstdlib> // Для использования rand()
#include "Puzzle.h"
#include "Phrase.h"
#include "Player.h"
using namespace std;

class Game {
private:
    Puzzle puzzles[MAX_PUZZLES];
    Player player;
    int currentPuzzle;
    Phrase phrases[MAX_PHRASES];

public:
    Game();
    void initializePuzzles();
    void initializePhrases();
    void setPlayerName(const char* playerName);
    const char* getPlayerName() const;
    int getPlayerScore() const;
    const char* getRandomPhrase() const;
    bool checkAnswer(int puzzleIndex, int answerIndex);
    void printPuzzle(int puzzleIndex) const;
    void printHint(int puzzleIndex) const;
    void startGame();
    void getAnswerAndCheck(int puzzleIndex);
};

#endif // GAME_H