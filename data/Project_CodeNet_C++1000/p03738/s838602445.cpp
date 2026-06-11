#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    string a, b;cin >> a >> b;

    if(a.size()>b.size()){
        out("GREATER");
    }
    else if(a.size()<b.size()){
        out("LESS");
    }
    else if(a>b){out("GREATER");}
    else if(a<b){
        out("LESS");
    }
    else{
        out("EQUAL");
    }
}