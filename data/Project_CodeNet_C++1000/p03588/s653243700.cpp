#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[100010],b[100010],cnt=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
    }
    sort(b,b+n);
    sort(a,a+n,greater<int>());
    cout<<a[0]+b[0]<<'\n';
    return(0);
}