#pragma once
#ifndef HINT_H
#define HINT_H

#define MAX_HINT_LENGTH 200

class Hint {
private:
    char text[MAX_HINT_LENGTH];
public:
    Hint();
    Hint(const char* hintText);
    const char* getText() const;
    void setText(const char* hintText);
};

#endif // HINT_H