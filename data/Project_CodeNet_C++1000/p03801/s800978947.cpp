#include <bits/stdc++.h>

using namespace std;
long long n,kq[100005],sl,x;
set<int> s;
pair<long long,int> a[100005];
int main()
{
  
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    s.insert(a[n].second);
    sl=a[n].first;
    for (int i=n-1;i>=0;--i)
     if (a[i].first==sl) s.insert(a[i].second);
    else
    {
        x=s.size();
        kq[(*s.begin())]+=(x*(sl-a[i].first));
        sl=a[i].first;
        s.insert(a[i].second);

    }

    for (int i=1;i<=n;++i) cout<<kq[i]<<'\n';
    return 0;
}
