#pragma once

struct Count
{
    int compare;
    int move;
    Count(int _compare = 0, int _move = 0): compare(_compare), move(_move) {}
    //Count &operator=(const Count& rhs)
    //{
        //compare = rhs.compare;
        //move = rhs.move;
        //return *this;
    //}

};
