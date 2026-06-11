#include<bits/stdc++.h>
using namespace std;
int a[10005],ans,n;
int main(void){
    cin>>n;
    for(int i=1;i<=2*n;i++) cin >> a[i];
    sort(a+1,a+1+2*n);
    for(int i=1;i<=2*n;i+=2) ans=ans+a[i];
    cout<<ans<<"\n";
}