#include <bits/stdc++.h>
#define MAXN 2010
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const ll mod = 1e9 + 7;

int main (){
    ios_base::sync_with_stdio(false);
    string s;
    int n, moves = 0;
    cin >> s;

    n = s.size();

    if ((n%2) ^ (s[0] == s[n-1])){
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
    }
    return 0;
}