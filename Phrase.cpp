#define _CRT_SECURE_NO_WARNINGS
#include "Phrase.h"
#include <cstring>

Phrase::Phrase() {
    strcpy(text, "");
}

Phrase::Phrase(const char* phraseText) {
    strcpy(text, phraseText);
}

const char* Phrase::getText() const {
    return text;
}

void Phrase::setText(const char* phraseText) {
    strcpy(text, phraseText);
}