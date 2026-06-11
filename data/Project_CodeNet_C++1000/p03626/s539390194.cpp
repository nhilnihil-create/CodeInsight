#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long mod = 1000000007;
    long long N;
    cin >> N;
    string s1, s2;
    cin >> s1 >> s2;
    vector<char> S1(N);
    vector<char> S2(N);
    for (long long i = 0; i < N; i++)
    {
        S1[i] = s1[i];
    }
    for (long long i = 0; i < N; i++)
    {
        S2[i] = s2[i];
    }
    
    long long ans;
    if (S1[0] == S2[0])
    {
        ans = 3;
    }
    else
    {
        ans = 6;
    }

    for (long long i = 1; i < N; i++)
    {
        if (S1[i] == S2[i])
        {
            if (S1[i-1] == S2[i-1])
            {
                ans = ans * 2 % mod;
            }
        }
        else
        {
            if (S1[i-1] == S2[i-1])
            {
                ans = ans * 2 % mod;
            }
            else if (S1[i-1] != S1[i] && S2[i-1] != S2[i])
            {
                ans = ans * 3 % mod;
            }
        }
    }
    cout << ans << endl;
}