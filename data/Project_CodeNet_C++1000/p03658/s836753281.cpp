#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
const int INF = 1001001001;

int main()
{
    int n,k,ans=0;
    in n>>k;
    vector<int> l(n);
    rep(i,n)in l[i];
    sort(l.begin(), l.end(), greater<int>());
    rep(i,k)ans+=l[i];
    cout<<ans<<endl;

}
