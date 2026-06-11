
/*
	*	Created By: 'Present_Sir'
	*	Created On: Wednesday 05 August 2020 11:28:54 AM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;

    vector<bool> v(10,1);
    for(int i=0; i<k; i++){
        int x;
        cin>>x;
        v[x]=0;
    }

    vector<int> ans;
    for(int i=n; i<=1e6+10; i++){
        int j = i;
        bool found = 1;
        ans.clear();
        while(j>0){
            ans.push_back(j%10);
            if(!v[j%10]){
                found = 0;
                break;
            }
            j /= 10;
        }
        if(found){
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
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

