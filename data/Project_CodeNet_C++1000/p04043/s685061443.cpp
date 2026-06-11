#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve()
{
    int a[3];
    int i,c=0,d=0;
    for(i=0;i<3;i++){
        cin>>a[i];
        if(a[i]==5) c++;
        if(a[i]==7) d++;
    }
    if(c==2&&d==1){
        cout<<"YES"<<endl;return;
    }
    else{
        cout<<"NO"<<endl;return;
    }
}
int main()
{
    solve();
}