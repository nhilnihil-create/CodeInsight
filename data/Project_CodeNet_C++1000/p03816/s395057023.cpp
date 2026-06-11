#include<bits/stdc++.h>
using namespace std;
int ara[100005];
int main()
{
    int n,a,b,count=0,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        ara[a]++;
    }
    for(i=0;i<=100000;i++){
        if(ara[i]>0) count++;
    }
    if((n-count) & 1) count--;
    cout<<count<<endl;
}
