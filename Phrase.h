#pragma once
#ifndef PHRASE_H
#define PHRASE_H

#define MAX_PHRASE_LENGTH 100

class Phrase {
private:
    char text[MAX_PHRASE_LENGTH];
public:
    Phrase();
    Phrase(const char* phraseText);
    const char* getText() const;
    void setText(const char* phraseText);
};

#endif // PHRASE_H