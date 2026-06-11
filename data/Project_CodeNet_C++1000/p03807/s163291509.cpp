#include<bits/stdc++.h>
using namespace std;
int n,a[100001],ans=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
         ans+=a[i];
    }
    if(ans%2==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}