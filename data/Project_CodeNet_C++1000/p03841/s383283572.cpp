#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500;
int ans[N*N], us[N*N];
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
    int n;
    cin>>n;
    vector<pair<int, int> > in;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        in.push_back({v-1, i+1});
    }
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(in[i].first==in[j].first){
        cout<<"No";
        return 0;
    }
    sort(in.begin(), in.end());
    int l=0;
    for(auto i:in){
        int cnt=i.second-1;
        while(cnt--){
            while(us[l])l++;
            if(l>=i.first){
                cout<<"No";
                return 0;
            }
            ans[l]=i.second;
            us[l]=1;
            l++;
        }
        ans[i.first]=i.second;
        us[i.first]=1;
    }
    sort(in.rbegin(), in.rend());
    l=n*n-1;
    for(auto i:in){
        int cnt=n-i.second;
        while(cnt--){
            while(us[l])l--;
            if(l<=i.first){
                cout<<"No";
                return 0;
            }
            ans[l]=i.second;
            us[l]=1;
            l--;
        }
        ans[i.first]=i.second;
        us[i.first]=1;
    }
    for(int i=0;i<n*n;i++){
        if(!us[i]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes\n";
    for(int i=0;i<n*n;i++)cout<<ans[i]<<' ';
}