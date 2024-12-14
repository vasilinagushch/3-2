#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H

#include "Option.h"
#include "Hint.h"

#define MAX_HINT_LENGTH 200
#define MAX_HINTS 3

class Puzzle {
private:
    char question[MAX_HINT_LENGTH];
    Option options[3];
    int correctAnswerIndex;
    Hint hints[MAX_HINTS];
    int attempts;
public:
    Puzzle();
    Puzzle(const char* question, int correctAnswerIndex, const char* hintText1, const char* hintText2, const char* hintText3, const char* option1, const char* option2, const char* option3);
    const char* getQuestion() const;
    const char* getOption(int index) const;
    const char* getHint(int index) const;
    int getCorrectAnswerIndex() const;
    int getAttempts() const;
    void incrementAttempts();
    void resetAttempts();
};

#endif // PUZZLE_H