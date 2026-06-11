#include<bits/stdc++.h>
using namespace std;
int n,k,a[51];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    nth_element(a+1,a+k+1,a+n+1,greater<int>());
    cout<<accumulate(a+1,a+k+1,0)<<endl;
    return 0;
}