#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int x[100000]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
        x[a[i]-1]++;
    }
    int eat=0;
    for(int i=0;i<100000;i++){
        if(x[i])eat+=x[i]-1;
    }
    if(eat%2)eat++;
    cout<<n-eat<<endl;
    return 0;
}