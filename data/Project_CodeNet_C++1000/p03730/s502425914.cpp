#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define inf 1000000100

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    a %= b;
    c %= b;
    for(int n = 0; n < b-1; n++)
    {
        if((a*n)%b == c%b)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}