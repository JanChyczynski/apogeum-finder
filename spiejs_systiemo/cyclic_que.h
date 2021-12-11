//
// Created by Jasiek on 11.12.2021.
//

#ifndef SPIEJS_SYSTIEMO_CYCLIC_QUE_H
#define SPIEJS_SYSTIEMO_CYCLIC_QUE_H

typedef int my_size_t;

template <class T, my_size_t N>
struct Cyclic_que
{
    T arr[N];
    my_size_t head = -1;

    T get(my_size_t pos)
    {
        return arr[(head-pos+N)%N];
    }

    void insert(T val)
    {
        head = (head+1)%N;
        arr[head] = val;
    }
};

#endif //SPIEJS_SYSTIEMO_CYCLIC_QUE_H
