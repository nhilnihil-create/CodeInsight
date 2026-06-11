#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a,ans=0,b[100005]={};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        b[a-1]++;
        b[a]++;
        b[a+1]++;
    }
    for(int i=0;i<=100000;i++){
        if(ans<b[i])
            ans=b[i];
    }   
    cout<<ans<<endl;
    return(0);
}