#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int k, s, count=0;
    cin >> k >> s;

    for (int i = 0; i < k + 1; i++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            if(0<=s-(i+j) && s-(i+j)<=k) count++;
        }
    }
    cout << count << endl;
    return 0;
}