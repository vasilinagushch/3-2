#pragma once
#ifndef OPTION_H
#define OPTION_H

#define MAX_OPTION_LENGTH 100

class Option {
private:
    char text[MAX_OPTION_LENGTH];
public:
    Option();
    Option(const char* optionText);
    const char* getText() const;
    void setText(const char* optionText);
};

#endif // OPTION_H