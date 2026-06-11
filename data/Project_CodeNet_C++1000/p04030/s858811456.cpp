#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    string S;
    cin >> S;
    deque<char> ans;
    for(auto s:S){
        if(s == 'B' && ans.empty())continue;
        if(s == 'B' && !ans.empty()){
            ans.pop_back();
        }else{
            ans.push_back(s);
        }
    }

    while(!ans.empty()){
        cout << ans.front();
        ans.pop_front();
    }
    cout << endl;
}