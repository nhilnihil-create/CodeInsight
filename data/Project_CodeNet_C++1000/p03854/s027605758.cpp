#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    string s; cin >> s;
    // 逆順にする
    reverse(all(s));
    bool ans = true;
    // 追加文字も逆順にする
    vector<string> dic = {"dream", "dreamer", "erase", "eraser"};
    rep(i, 4) reverse(all(dic[i]));

    while(s.size() > 0){
        // mから始まるのはdreamの逆しかない
        if(s[0] == 'm'){
            if(s.substr(0, 5) == dic[0]) s = s.substr(5);
            else{
                ans = false;
                break;
            }
        }
        // eから始まるのはeraseの逆しか無い
        else if(s[0] == 'e'){
            if(s.substr(0, 5) == dic[2]) s = s.substr(5);
            else{
                ans = false;
                break;
            }
        }
        // reで始まるのは2種類なのでどっちも試す
        else{
            if(s.substr(0, 6) == dic[3]) s = s.substr(6);
            else if(s.substr(0, 7) == dic[1]) s = s.substr(7);
            else{
                ans = false;
                break;
            }
        }
    }
    (ans) ? YES() : NO();
}