#include<bits/stdc++.h>
using namespace std;
/*
alias p='g++ -std=c++17 -O2 pra.cpp'
alias pg='g++ -std=c++17 -O2 -g pra.cpp'
alias s='g++ -std=c++17 -O2 -g subpra.cpp'
alias ss='g++ -std=c++17 -O2 -g sspra.cpp'
ulimit -c unlimited
alias a='./a.out'
cd programming
cd cpp
cd practice

*/
using ll = long long;
#define rep(i, n) for(int i=0; i<(n); i++)
//if (i) cout << " "; で最初のみ空白文字を出力することができる
#define Sort(v) sort((v).begin(), (v).end())
#define pb push_back
using veci = vector<int>;
using vecs = vector<string>;
using vecd = vector<double>;
using vecl = vector<long long>;
using G = vector<vector<int>>;
using P = pair<int, int>;
double PI = acos(-1);
ll lINF = LLONG_MAX; ll lmINF = LLONG_MIN;
int INF = INT_MAX; int mINF = INT_MIN;
//const ll mod = 1000000007;
int main() {
    cout.precision(10);
    cin.tie(0);//cin高速化
    string s;
    cin >> s;
  int N = s.size();
    ll ans = 0;
    ll temp;
    for (int bit=0; bit < (1<<(N-1)); bit++){//2通りある部分で、全パターンの列挙
        temp = 0;//最初に見る値まで10倍されては困る
        for (int i=0; i<N-1; i++){//+が入らない限り、10倍して1の位に入れる操作を繰り返す(この10倍して1の位に入れる、という操作は重要)
            temp *= 10;
            temp += s[i] - '0';
            if (bit&(1 << i)){//フラグが立っていれば
                ans += temp;
                temp = 0;
            }
        }
        temp *= 10;//一個前にまとめられてなければ最後もまとめられる
        temp += s.back()-'0';//最後の要素は絶対に10倍されないので別で足す
        ans += temp;
    }
    cout << ans << endl;
    return 0;
}
