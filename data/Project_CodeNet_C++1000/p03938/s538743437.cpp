#include <bits/stdc++.h>
using namespace std;
int n,p[20009],a[20009],b[20009];
int main(){
    cin>>n;
    for(int i=0;i++<n;){
        cin>>p[i];
        a[i]+=i*30000;
        b[n-i+1]+=i*30000;
        b[p[i]]+=i;
    }
    for(int i=0;i++<n;){
        if(i!=1)cout<<" ";
        cout<<a[i];
    }cout<<endl;
    for(int i=0;i++<n;){
        if(i!=1)cout<<" ";
        cout<<b[i];
    }cout<<endl;
}