#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(int i=0; i<n; i++)
#define rep(i,start,n) for(int i=start; i<n; i++)

signed main(){
    fast;  

    int n;cin>>n;
    int mn = 200;
    int sum = 0;
    int s[n];

    loop(n){
    	cin>>s[i];
    	sum+=s[i];
    	if( s[i]%10!=0 )
    		mn = min(mn,s[i]);  	
    }
    if(mn==200){
    	cout<<0<<endl;
    	return 0;
    }
    if(sum%10!=0)
    	cout<<sum<<endl;
    else{
    	sum-=mn;
    	cout<<sum<<endl;
    }
    
    
    return 0;
}
