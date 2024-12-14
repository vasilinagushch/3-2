#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include "Phrase.h"
#include "Player.h"
#include "Puzzle.h"

Game::Game() : currentPuzzle(0) {}

void Game::initializePuzzles() {
    puzzles[0] = Puzzle("��� ����� ���� ����� � ����, �� ��� ���� �� ���������?", 0, "� ����� �������� ���� ���������.", "�� ������ ��������� ��� � ������.", "��� �������� ����� ������������ ����� �������.", "��������", "���������", "����");
    puzzles[1] = Puzzle("�� �� �����, �� �� �������, ���������� - � ����� �������.", 1, "��� ����������� ����������.", "� ���� ���� ������ � ����� �������.", "� ���� ��� �����.", "���������", "�������", "������");
    puzzles[2] = Puzzle("� ������ ��� ��� � ����� ��� ����. ��� � �����?", 1, "��� ��������� �������, ������� �� ������ ��������.", "��� ���������, ����� ���� ���������� �� �����������.", "�� ������ ������� ��� � ����� ��� �������.", "�����", "���", "�����");
}

void Game::initializePhrases() {
    phrases[0] = Phrase("� ���� ������� ������� �����.\n");
    phrases[1] = Phrase("� ���� ������� ������� �����.\n");
    phrases[2] = Phrase("��� ������� �������� �� �������.\n");
}

void Game::setPlayerName(const char* playerName) {
    player = Player(playerName);
}

const char* Game::getPlayerName() const {
    return player.getName();
}

int Game::getPlayerScore() const {
    return player.getScore();
}

const char* Game::getRandomPhrase() const {
    int randomIndex = rand() % MAX_PHRASES;
    return phrases[randomIndex].getText();
}

bool Game::checkAnswer(int puzzleIndex, int answerIndex) {
    if (answerIndex == puzzles[puzzleIndex].getCorrectAnswerIndex()) {
        player.incrementScore();
        return true;
    }
    else {
        puzzles[puzzleIndex].incrementAttempts();
        return false;
    }
}

void Game::printPuzzle(int puzzleIndex) const {
    cout << "�������: " << puzzles[puzzleIndex].getQuestion() << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ") " << puzzles[puzzleIndex].getOption(i) << endl;
    }
}

void Game::printHint(int puzzleIndex) const {
    int attempts = puzzles[puzzleIndex].getAttempts();
    if (attempts < MAX_HINTS) {
        cout << "���������: " << puzzles[puzzleIndex].getHint(attempts) << endl;
    }
}

void Game::startGame() {
    for (currentPuzzle = 0; currentPuzzle < MAX_PUZZLES; currentPuzzle++) {
        printPuzzle(currentPuzzle);
        getAnswerAndCheck(currentPuzzle);
    }
    cout << "���� ���������! " << getPlayerName() << " �����(�) " << getPlayerScore() << " �������." << endl;
    if (getPlayerScore() == 0) {
        cout << "�� �� ������ �� ����� �������. ���������� �����!\n" << endl;
        player.resetScore();
        startGame();
    }
}

void Game::getAnswerAndCheck(int puzzleIndex) {
    int answerIndex;
    cout << "������� ����� ������ (1-3): ";
    cin >> answerIndex;

    if (checkAnswer(puzzleIndex, answerIndex - 1)) {
        cout << "���������! �������!\n" << endl;
        cout << getRandomPhrase() << endl;
    }
    else {
        if (puzzles[puzzleIndex].getAttempts() < MAX_ATTEMPTS) {
            printHint(puzzleIndex);
            getAnswerAndCheck(puzzleIndex);
        }
        else {
            cout << "��� ������� �������. ������� � ��������� �������.\n" << endl;
        }
    }
}