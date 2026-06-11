#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    string s; cin >> s;
    int sl = (int)s.length();
    string temp = "";
    temp.push_back(s[0]);

    for (int i = 1; i < sl; i++)
    {
        if(s[i]!=s[i-1]) temp.push_back(s[i]);
    }

    cout << (int)temp.length()-1<< endl;
    
}