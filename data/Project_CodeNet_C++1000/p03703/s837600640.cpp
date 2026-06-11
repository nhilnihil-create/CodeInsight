#include <bits/stdc++.h>

using namespace std;

int BIT[300000];

int Sum(int I)
{
    long long S=0;
    I = 300000-I;
    I -= 2;
    I++;
    while (I > 0)
    {
        S += BIT[I];
        I -= I & (-I);
    }
    return S;
}

void Update(int I)
{
    I = 300000-I;
    I -= 2;
    I++;
    while (I < 300000)
    {
        BIT[I]++;
        I += I & (-I);
    }
}

int main()
{
    for (int i = 0; i < 300000; i++)
    {
        BIT[i] = 0;
    }
    int n, K, k=0;
    long long a, S=0, R=0;
    cin >> n >> K;
    long long A[n];
    set <long long> SL;
    set <long long> :: iterator it1;
    map <long long,int> Ma;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        a -= K;
        A[i] = a;
        if (i != 0)
        {
            S += a;
        }
        SL.insert(a-S);
    }
    for (set <long long> :: iterator it = SL.begin(); it != SL.end(); it++)
    {
        Ma[*it] = k;
        k++;
    }
    S = 0;
    for (int i = 0; i < n; i++)
    {
        a = A[i];
        if (i != 0)
        {
            S += a;
        }
        Update(Ma[a-S]);
        it1 = SL.lower_bound((-1)*S);
        if (it1 != SL.end())
        {
            R += Sum(Ma[*SL.lower_bound((-1)*S)]);
        }
    }
    cout << R;
    return 0;
}
