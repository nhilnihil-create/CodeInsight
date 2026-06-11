#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(void){
    int n;
    ll m=0,t;
    vector<ll> v;
    cin>>n;
    for(int i=1;m<10000000;i++){
        m+=i;
        v.push_back(m);
    }
    for(int i=0;i<v.size();i++){
        if(n<=v[i]){
            m=i+1;
            t=v[i]-n;
            break;
        }
    }
    for(int i=1;i<=m;i++){
        if(i!=t)cout<<i<<endl;
    }
}
