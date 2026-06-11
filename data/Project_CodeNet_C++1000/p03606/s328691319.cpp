#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n,ans=0,l,r;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        ans+=r-l+1;
    }
    cout<<ans<<endl;
    return(0);
}