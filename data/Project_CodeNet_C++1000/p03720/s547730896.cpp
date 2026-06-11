#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n,m;
    cin>>n>>m;

    vector<int> r(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        r[a]++;
        r[b]++;
    }

    for(int i=1;i<=n;i++){
        cout<<r[i]<<endl;
    }

}
