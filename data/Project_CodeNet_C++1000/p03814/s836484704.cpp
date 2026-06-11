#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
    string s;
    cin >> s;
    int a = inf, z = 0;
    for(int i = 0; s[i]; i++)
    {
        if(s[i] == 'A') a = min(a, i);
        if(s[i] == 'Z') z = max(z, i);
    }

    cout << z - a + 1<< endl;
}
