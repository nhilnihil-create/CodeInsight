#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,a[101],b[51]={0};
    cin>>n>>m;
    for(i=0;i<2*m;i++){
        cin>>a[i];
    }
    sort(a,a+2*m);
    int sum=1;
    for(i=0;i<2*m;i++){
        if(a[i]==a[i+1]){
            sum+=1;
        }
        else if(a[i]!=a[i+1]){
            b[a[i]-1]=sum;
            sum=1;
        }
    }
    for(i=0;i<n;i++){
        cout<<b[i]<<'\n';
    }
    return 0;
}
