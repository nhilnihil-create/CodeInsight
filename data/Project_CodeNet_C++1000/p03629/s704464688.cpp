#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    string A;
    cin >> A;
    int s=A.size();
    vector<vector<int>> pos(26);
    rep(i,s) pos[A[i]-'a'].push_back(i);
    string ans="";
    queue<pair<int,string>> que;
    que.push(make_pair(-1,""));
    vector<bool> used(s,false);
    bool finished=false;
    while(!finished){
        pair<int,string> p=que.front();
        que.pop();
        int now=p.first;
        string S=p.second;
        rep(i,26){
            if (upper_bound(pos[i].begin(),pos[i].end(),now)==pos[i].end()){
                if (ans==""||ans.size()>(int)S.size()+1) ans=S+char('a'+i);
                finished=true;
            }
            else {
                int next=*upper_bound(pos[i].begin(),pos[i].end(),now);
                if (!used[next]){
                    que.push(make_pair(next,S+char('a'+i)));
                    used[next]=true;
                }
            }
        }
    }
    cout << ans << endl;
}