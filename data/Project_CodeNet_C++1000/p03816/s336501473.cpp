#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;
map<int,int>mp;
const int N=1e7+100;
int n,m;
set<int>s;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(s.find(x)!=s.end()) cnt++;
        else s.insert(x);
    }
    int ans=s.size();
    if(cnt&1) ans--;
    cout<<ans<<endl;
    return 0;
}
