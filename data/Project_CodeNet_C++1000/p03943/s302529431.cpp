#include<bits/stdc++.h>
#define FOR(i,n,m) for(int i=n;i<=m;i++)
using namespace std;
int main(){
    int a[5];
    FOR(i,1,3)
    cin>>a[i];
    sort(a+1,a+4);

    if(a[1]+a[2]==a[3])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}