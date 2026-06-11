
#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define MOD 1e9+7
#define EPS 1e-8
#define INF 1e9+10
typedef long long ll;
using namespace std;
int main()
{
    string s;
    cin >> s;
    rep(i,0,s.length()){
        cout << s[i];
        if(i==3){cout << " ";}
    }
    cout << endl;
}

