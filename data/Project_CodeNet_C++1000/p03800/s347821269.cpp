#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using ll=long long;
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    rep(k,2)rep(h,2){//最初の文字4パターンを試す
         bool judge=true;
        vector<int>ans;
        ans.pb(k);ans.pb(h);//狼:0　羊:1
    for(int i=2;i<n;++i){
        if(ans[i-1]){
        if(s[i-1]=='x')ans.pb(1-ans[i-2]);
        else ans.pb(ans[i-2]);
        }
        else {
            if(s[i-1]=='x')ans.pb(ans[i-2]);
            else ans.pb(1-ans[i-2]);
        }
    }
    string t="";
    rep(i,n){
        if(ans[i])t+="S";
        else t+="W";
    }
    t.insert(t.begin(),t[n-1]);
    t.push_back(t[1]);
    for(int i=1;i<=n;++i){
            if(ans[i-1]){
                if(s[i-1]=='o'){
                    if(t[i-1]!=t[i+1])judge=false;
                }
                else if(s[i-1]=='x'){
                    if(t[i-1]==t[i+1])judge=false;
                }
            }
            else {
                if(s[i-1]=='x'){
                    if(t[i-1]!=t[i+1])judge=false;
                }
                else if(s[i-1]=='o'){
                    if(t[i-1]==t[i+1])judge=false;
                }
            }
        if(!judge){
            break;
        }
    }
    if(judge){
        t.erase(t.begin());
        t.pop_back();
        cout<<t<<endl;
        return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}