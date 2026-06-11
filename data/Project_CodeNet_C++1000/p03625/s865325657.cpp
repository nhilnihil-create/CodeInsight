#include<bits/stdc++.h>
using namespace std;
#define ll long long int     
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,greater<ll>());
    vector<ll>v;
    for(int i=0;i<n-1;){
        if(a[i]==a[i+1]){
            v.push_back(a[i]);
            i=i+2;
        }else i++;
        if(v.size()>=2)break;
    }
    ll area=1;
    for(int i=0;i<v.size();i++)area*=v[i];
    if(v.size()==2)cout<<area;
    else cout<<0;
}