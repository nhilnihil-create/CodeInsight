#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
string s;
int n;
string a[4]={"dream", "dreamer", "erase", "eraser"};
bool vis[N],dp[N];
bool solve( int i ) {
    if ( i==n ) return 1;
    if ( vis[i] ) return dp[i];
    vis[i]=1;
    for ( int j=0; j<4; j++ ) {
        string t=a[j];
        int x=0;
        while ( x<t.size()&&i+x<n&&s[i+x]==t[x] ) {
            x++;
        }
        if ( x==t.size()&&solve(i+x) ) {
            return dp[i]=true;
        }
    }
    return dp[i]=false;
}

int main() {
    cin >> s;
    n=s.size();
    if ( solve(0) ) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}