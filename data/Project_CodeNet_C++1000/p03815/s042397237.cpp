#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} //配列vにn個の要素を入力する
#define rep(i, l, n) for (int i = l; i < (int)(n); i++)
#define repn(i, l, n) for (int i = l; i <= (int)(n); i++)

const int mod = 1000000007;

int main(){
    ll x;
    cin >> x;
    ll a = x / 11;
    ll b = x % 11;
    if(b==0){b = 0;}else if(b <= 6){b = 1;}else{b = 2;}
    cout << a*2+b;
}