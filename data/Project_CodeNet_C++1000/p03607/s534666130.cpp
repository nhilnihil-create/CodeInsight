#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    map<long long,long long> a;
    int n,ans=0,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b;
        if(a[b]!=1){
            a[b]=1;
            ans++;
        }
        else{
            a[b]=0;
            ans--;
        }
    }
    cout<<ans<<endl;
    return(0);
}