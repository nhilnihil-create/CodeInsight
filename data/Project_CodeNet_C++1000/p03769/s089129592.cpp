#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
ll n;int l,r;
vector<int> Q(ll n){
    vector<int> ans;
    if (n<=2){
        for (int i=1;i<=n;i++) ans.push_back(--l);
        return ans;
    }
    ans=Q((n-1)>>1);
    ans.push_back(++r);
    if (!(n&1)) ans.push_back(--l);
    return ans;
}
vector<int> a;
int main()
{
    scanf("%lld",&n);
    l=51;r=50;
    a=Q(n);
    for (int i=l;i<=r;i++) a.push_back(i);
    printf("%d\n",(int)a.size());
    for (int i=0;i<a.size();i++) printf("%d ",a[i]);
    puts("");
    return 0;
}