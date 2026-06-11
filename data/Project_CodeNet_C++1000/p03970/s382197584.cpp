#include <bits/stdc++.h>
#define rep(i, N) for (long long i = 0; i < N; i++)
using namespace std;

int main()
{
    string T = "CODEFESTIVAL2016", S;
    cin >> S;
    int count = 0;
    rep(i, 16)
    {
        if (S[i] != T[i])
        {
            count++;
        }
    }
    cout << count << endl;
}