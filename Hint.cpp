#define _CRT_SECURE_NO_WARNINGS
#include "Hint.h"
#include <cstring>

Hint::Hint() {
    strcpy(text, "");
}

Hint::Hint(const char* hintText) {
    strcpy(text, hintText);
}

const char* Hint::getText() const {
    return text;
}

void Hint::setText(const char* hintText) {
    strcpy(text, hintText);
}