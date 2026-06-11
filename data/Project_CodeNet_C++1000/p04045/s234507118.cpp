#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;

ll N,K;
vll d;

void dfs(vector<string>& enm,string cur)
{
    if(cur!=""){
        if(N<=stoi(cur))enm.push_back(cur);
        if(5<cur.size())return;
    }
    for(ll i=0;i<10;i++)
    {
        if(find(d.begin(),d.end(),i)!=d.end())continue;
        cur.push_back('0'+i);
        dfs(enm,cur);
        cur.pop_back();
    }
}

int main()
{
    cin>>N>>K;
    d=vll(K);
    for(ll i=0;i<K;i++)cin>>d[i];
    
    vector<string> enm;
    vector<ll> res;

    dfs(enm,"");
    for(ll i=0;i<enm.size();i++)
    {
       res.emplace_back(stoi(enm[i]));
    }
    sort(res.begin(),res.end());
    cout<<res[0]<<endl;
}