#include <iostream>
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
ll n,m,a,b,ant=1000000000,key,ch[100000];
vector<ll>v[100000],ans;
map<ll,ll>mp;
void f(ll n){
    for(ll x:v[n]){
        //cout<<x<<" "<<ch[x]<<endl;
        if(ch[x]==0){
            ch[x]=1;
            ans.push_back(x+1);
            f(x);
            return ;
        }
    }
    return ;
}
int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        mp[a]++;
        mp[b]++;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    for(auto xx:mp){
        if(ant>xx.S){
            ant=xx.S;
            key=xx.F;
        }
    }
    //cout<<key<<"W"<<endl;
    //cout<<"KE"<<key<<endl;
    ch[key-1]=1;
    ans.push_back(key);
    f(key-1);
    ll tmp=ans.size();
    //cout<<endl;
    f(key-1);
    ll N=ans.size();
    cout<<N<<endl;
    for(int i=0;i<N-tmp;i++){
        cout<<ans[N-i-1]<<" ";
    }
    for(int i=0;i<tmp;i++){
        cout<<ans[i]<<" ";;
    }
    cout<<endl;
}
