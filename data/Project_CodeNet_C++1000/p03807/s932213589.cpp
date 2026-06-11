#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int odd = 0;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        if (a % 2 == 1)
        {
            ++odd;
        }
    }
    if (odd % 2 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}