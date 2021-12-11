#include "cyclic_que.h"
#include <iostream>
#include <assert.h>

using namespace std;

void test1()
{
    Cyclic_que<int, 3> que;

    que.insert(5);
    assert(que.get(0) == 5);
    que.insert(4);
    assert(que.get(0) == 4);
    assert(que.get(1) == 5);
    que.insert(7);
    assert(que.get(0) == 7);
    assert(que.get(1) == 4);
    assert(que.get(2) == 5);
    for (int i = 0; i < 10; ++i)
    {
        que.insert(i);
    }
    assert(que.get(0) == 9);
}

int main()
{
    test1();
}