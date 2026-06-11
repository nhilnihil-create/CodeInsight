#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define forn(i, n) for (int i = 0; i < (int) (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int size = s.size();
    string res;
    if(size%2 == 0){
        if(s[0] == s[size-1]){
            res =  "First";
        }else{  
            res =  "Second";
        }
    }else{
        if(s[0] == s[size-1]){
            res =  "Second";
        }else{
            res =  "First";
        }
    }
    cout << res;
    return 0;
}