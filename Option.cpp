#define _CRT_SECURE_NO_WARNINGS
#include "Option.h"
#include <cstring>

Option::Option() {
    strcpy(text, "");
}

Option::Option(const char* optionText) {
    strcpy(text, optionText);
}

const char* Option::getText() const {
    return text;
}

void Option::setText(const char* optionText) {
    strcpy(text, optionText);
}