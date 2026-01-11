#pragma once

class Terminal {
public:
    int x;
    int y;
    Terminal();
    ~Terminal();
    Terminal(const Terminal&) = delete;
    Terminal& operator=(const Terminal&) = delete;
    void savePostion();
};
