#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
using ll = long long;
#define vl vector<long long>
#define vll vector<vector<long long>>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
//以上テンプレ

int main(){
    string X;
    cin>>X;
    stack<char> ans;
    ll a=X.size();
    rep(i,a){
        if(X.at(i)=='S'){
            ans.push('S');
        }else if(X.at(i)=='T'&&ans.empty()){
            ans.push('T');
        }else if(X.at(i)=='T'&&ans.top()=='S'){
            ans.pop();
        }else{
            ans.push('T');
        }
    }
    cout<<ans.size()<<endl;
}