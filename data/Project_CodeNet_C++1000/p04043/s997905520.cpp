
/*
	*	Created By: 'Present_Sir'
	*	Created On: Wednesday 05 August 2020 11:17:55 AM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
using namespace std;


void solve(){
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    
    sort(a, a+3);
    if(a[0] != 5 || a[1] !=5 || a[2] != 7){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}

int32_t main(){
    IOS;
    //int t; cin>>t; while(t--)
    {
        solve();
    }
    return 0;
}

