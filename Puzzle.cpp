#define _CRT_SECURE_NO_WARNINGS
#include "Puzzle.h"
#include <cstring>

Puzzle::Puzzle() : correctAnswerIndex(0), attempts(0) {
    strcpy(question, "");
}

Puzzle::Puzzle(const char* question, int correctAnswerIndex, const char* hintText1, const char* hintText2, const char* hintText3, const char* option1, const char* option2, const char* option3) {
    strcpy(this->question, question);
    this->correctAnswerIndex = correctAnswerIndex;
    hints[0].setText(hintText1);
    hints[1].setText(hintText2);
    hints[2].setText(hintText3);
    options[0].setText(option1);
    options[1].setText(option2);
    options[2].setText(option3);
    attempts = 0;
}

const char* Puzzle::getQuestion() const {
    return question;
}

const char* Puzzle::getOption(int index) const {
    return options[index].getText();
}

const char* Puzzle::getHint(int index) const {
    return hints[index].getText();
}

int Puzzle::getCorrectAnswerIndex() const {
    return correctAnswerIndex;
}

int Puzzle::getAttempts() const {
    return attempts;
}

void Puzzle::incrementAttempts() {
    attempts++;
}

void Puzzle::resetAttempts() {
    attempts = 0;
}