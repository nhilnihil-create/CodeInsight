#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n,m;
    cin>>n>>m;
    int x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(x,x+n);
    vector<int> a[m]={};
    for(int i=0;i<n;i++){
        a[x[i]%m].push_back(x[i]);
    }
    ll ans=a[0].size()/2;
    for(int i=1;i<=m/2;i++){
        int b;
        if(i!=m-i) b=min(a[i].size(),a[m-i].size());
        else b = a[i].size()/2;
        ans += b;
        if(i==m-i) b*=2;
        if(a[i].size()-b){
            int c=a[i].size()-b;
            int j=1;
            while(j<a[i].size() && c>1){
                if(a[i][j] == a[i][j-1]){
                    ans++;
                    j+=2;
                    c-=2;
                }
                else j++;
            }
        }
        if(i!=m-i && a[m-i].size()-b){
            int c=a[m-i].size()-b;
            int j=1;
            while(j<a[m-i].size() && c>1){
                if(a[m-i][j] == a[m-i][j-1]){
                    ans++;
                    j+=2;
                    c-=2;
                }
                else j++;
            }
        }
        cerr<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;

    
}