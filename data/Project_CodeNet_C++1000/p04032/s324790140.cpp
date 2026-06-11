#include <bits/stdc++.h>
using namespace std;
long long m=1e9+7;
long long fact[1000001],inv[1000001];

long long modRecursive(long long a,long long b,long long c)
{
	if(b == 0) return 1;
	if(b%2 ==0) return modRecursive((a*a)%c,b/2,c);
	else return ((a%c)*(modRecursive((a*a)%c,b/2,c)))%c;
}
int main()
{
    string S;
    cin >> S;

    for(int i = 0; i + 1 < S.size(); i++)
    {
        if(S[i] == S[i + 1])
        {
            cout << i + 1 << " " << i + 2;
            return 0;
        }

        if(i + 2 < S.size() && S[i] == S[i + 2])
        {
            cout << i + 1 << " " << i + 3;
            return 0;
        }
    }

    cout << "-1 -1";
    return 0;
}
