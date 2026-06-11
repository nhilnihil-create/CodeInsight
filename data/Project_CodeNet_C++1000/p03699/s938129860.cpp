#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n,s[105],sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        sum+=s[i];
    }
    sort(s,s+n);
    for(int i=0;i<n;i++){
        if(sum%10!=0){
            cout<<sum<<endl;
            return(0);
        }
        if(s[i]%10!=0)
            sum-=s[i];
    }
    if(sum%10!=0){
            cout<<sum<<endl;
            return(0);
        }
    cout<<"0"<<endl;
    return(0);
}