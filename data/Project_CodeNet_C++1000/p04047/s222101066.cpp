#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int N, num;
    int sum = 0;
    vector<int> L;

    // input
    cin >> N;

    for (int i = 0 ; i < 2*N ; i++)
    {
        cin >> num;
        L.push_back(num);
    }

    sort(L.begin(), L.end());
    for (int i = 0 ; i < N ; i++)
    {
        sum += L[2*i];
    }
    cout << sum << endl;
    return 0;
}