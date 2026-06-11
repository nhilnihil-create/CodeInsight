#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    long long n,a[300005],ans=0;
    cin>>n;
    for(int i=0;i<n*3;i++){
        cin>>a[i];
    }
    sort(a,a+n*3,greater<long long>());
    for(int i=1;i<2*n;i+=2){
        ans+=a[i];
    }
    cout<<ans<<endl;
	return(0);
}