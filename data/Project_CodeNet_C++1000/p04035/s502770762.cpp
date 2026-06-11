#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+77;
int in[N];
signed main()
{
#ifdef home
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#else
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int n, l;
    cin>>n>>l;
    for(int i=1;i<=n;i++){
        cin>>in[i];
    }
    vector<int> ans;
    for(int i=1;i<n;i++){
        if(in[i]+in[i+1]>=l){
            ans.push_back(i);
            break;
        }
    }
    if(ans.empty()){
        cout<<"Impossible";
        return 0;
    }
    for(int i=ans[0]+1;i<n;i++)ans.push_back(i);
    for(int i=ans[0]-1;i>0;i--)ans.push_back(i);
    reverse(ans.begin(), ans.end());
    cout<<"Possible\n";
    for(int i:ans)cout<<i<<'\n';
}