#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define D(i, a, b) for (int i = (a); i >= (b); i--)
#define R(i, a, b) for (int i = (a); i < (b); i++)
#define N 500000
#define ALL(vt) vt.begin(), vt.end()
void solve(string s)
{
    int n = s.length();
    
    if(n <= 3){
        map<char, int> dem;
        for(char c : s){
            ++dem[c];
        }
        if(n != dem.size())  cout << 1 << " " << n;
        else cout << -1 << " " << -1;
        return;
    }
    R(i, 0, n - 3)
    {
        map<char, int> dem;
        R(j, i, i + 3) ++dem[s[j]];        
        if (dem.size() != 3)
        {
            cout << i + 1 << " " << i + 3;
            return;
        }
    }
    cout << -1 << " " << -1;
}
int main()
{

    string s;
    cin >> s;
    solve(s);
    return 0;
}