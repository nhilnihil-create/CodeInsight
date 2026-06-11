#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, A;
    cin >> N;
    cin >> A;
    N = N * N;
    N = N - A;
    cout << N << endl;
}