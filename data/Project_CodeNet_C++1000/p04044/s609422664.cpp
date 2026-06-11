
/*
	*	Created By: 'Present_Sir'
	*	Created On: Wednesday 05 August 2020 11:24:47 AM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
using namespace std;


void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        cout<<v[i];
    }
    cout<<endl;
}

int32_t main(){
    IOS;
    //int t; cin>>t; while(t--)
    {
        solve();
    }
    return 0;
}

