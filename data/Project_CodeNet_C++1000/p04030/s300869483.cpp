#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<math.h>
#include<string>
#include <cctype>
#include <cstdlib>
#include<bitset>
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
    string s; cin >> s;
    string str="";
    rep(i, s.size()){
        if(s[i]=='0'){
            str+='0';
        }
        else if(s[i]=='1'){
            str+='1';
        }
        else{
            if(str=="")continue;
            else str.erase(str.end()-1);
        }
    }
    out(str);
}