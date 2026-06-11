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
    map<char, int> m;
    rep(i, s.size()){
        m[s[i]]++;
    }

    auto begin = m.begin(), end=m.end();
    int temp;
    bool flag=true;
    for(auto iter =  begin; iter != end; iter++){
        temp = iter->second;
        if(temp%2!=0){
            flag = false;
        }
    }

    if(flag){
        out("Yes");
    }
    else{
        out("No");
        }
}