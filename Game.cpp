#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include "Phrase.h"
#include "Player.h"
#include "Puzzle.h"

Game::Game() : currentPuzzle(0) {}

void Game::initializePuzzles() {
    puzzles[0] = Puzzle("Что может идти вверх и вниз, но при этом не двигается?", 0, "У этого предмета есть ступеньки.", "Ты можешь встретить его в здании.", "Это помогает людям перемещаться между этажами.", "Лестница", "Эскалатор", "Лифт");
    puzzles[1] = Puzzle("То ли зебра, то ли лесенка, прикоснись - и будет песенка.", 1, "Это музыкальный инструмент.", "У него есть черные и белые клавиши.", "У него нет струн.", "Эскалатор", "Пианино", "Гитара");
    puzzles[2] = Puzzle("Я говорю без рта и слышу без ушей. Что я такое?", 1, "Это природное явление, которое ты можешь услышать.", "Оно возникает, когда звук отражается от поверхности.", "Ты можешь слышать его в горах или пещерах.", "Голос", "Эхо", "Ветер");
}

void Game::initializePhrases() {
    phrases[0] = Phrase("У дома Круэллы красная крыша.\n");
    phrases[1] = Phrase("У дома Круэллы красная дверь.\n");
    phrases[2] = Phrase("Дом Круэллы построен из кирпича.\n");
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
    cout << "Загадка: " << puzzles[puzzleIndex].getQuestion() << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ") " << puzzles[puzzleIndex].getOption(i) << endl;
    }
}

void Game::printHint(int puzzleIndex) const {
    int attempts = puzzles[puzzleIndex].getAttempts();
    if (attempts < MAX_HINTS) {
        cout << "Подсказка: " << puzzles[puzzleIndex].getHint(attempts) << endl;
    }
}

void Game::startGame() {
    for (currentPuzzle = 0; currentPuzzle < MAX_PUZZLES; currentPuzzle++) {
        printPuzzle(currentPuzzle);
        getAnswerAndCheck(currentPuzzle);
    }
    cout << "Игра завершена! " << getPlayerName() << " решил(а) " << getPlayerScore() << " загадок." << endl;
    if (getPlayerScore() == 0) {
        cout << "Вы не решили ни одной загадки. Попробуйте снова!\n" << endl;
        player.resetScore();
        startGame();
    }
}

void Game::getAnswerAndCheck(int puzzleIndex) {
    int answerIndex;
    cout << "Введите номер ответа (1-3): ";
    cin >> answerIndex;

    if (checkAnswer(puzzleIndex, answerIndex - 1)) {
        cout << "Правильно! Молодец!\n" << endl;
        cout << getRandomPhrase() << endl;
    }
    else {
        if (puzzles[puzzleIndex].getAttempts() < MAX_ATTEMPTS) {
            printHint(puzzleIndex);
            getAnswerAndCheck(puzzleIndex);
        }
        else {
            cout << "Три попытки истекли. Переход к следующей загадке.\n" << endl;
        }
    }
}