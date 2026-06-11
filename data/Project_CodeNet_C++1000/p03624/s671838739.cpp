#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int c[26];

int main(){
    string s;
    cin >> s;
    rep(i,s.size()) c[s[i]-'a'] ++;
    rep(i,26){
        if(c[i]==0){
            cout << (char)('a'+i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}
