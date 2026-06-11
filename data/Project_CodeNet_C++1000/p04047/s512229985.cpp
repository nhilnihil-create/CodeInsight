#include<bits/stdc++.h>
using namespace std;
int n,sum=0,l[205];
int main(){
    cin>>n;
    for(int i=1;i<=2*n;i++) cin>>l[i];
    sort(l+1,l+2*n+1);
    for(int i=1;i<=2*n;i+=2) sum+=l[i];
    cout<<sum<<endl;	
    return 0;
}