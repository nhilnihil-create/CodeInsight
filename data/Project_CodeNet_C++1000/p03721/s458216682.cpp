#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; ll k; cin>>n>>k;
    map<int, ll> list;
    for(int i=0; i<n; i++){
        int a; ll b; cin>>a>>b;
        if(list.count(a)) list[a]+=b;
        else list[a]=b;
    }
    ll num = 0;
    auto begin = list.begin(), end = list.end();
    int l;
    for(auto iter = begin; iter!=end; iter++){
        num += iter->second;
        l = iter->first;
        if (num >=k)break;
    }
    cout << l << endl;
}