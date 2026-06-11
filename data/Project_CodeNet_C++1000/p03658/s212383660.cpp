#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,l[100],ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    sort(l,l+n,greater<int>());
    for(int i=0;i<k;i++){
        ans+=l[i];
    }
    cout<<ans<<endl;
    return(0);
}