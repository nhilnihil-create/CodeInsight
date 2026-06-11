#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
const int maxn=100001;
string A,B;
int suma1[maxn],suma2[maxn], sumb1[maxn],sumb2[maxn],n,m;
void enter()
{
    cin>>A>>B;
    n=int (A.size());
    m=int(B.size());
    _for(i,0,n)
    {
        suma1[i+1]+=suma1[i];
        sumb1[i+1]+=sumb1[i];
        if (A[i]=='A')
            suma1[i+1]++;
        else sumb1[i+1]++;
    }
    _for(i,0,m){
        suma2[i+1]+=suma2[i];
        sumb2[i+1]+=sumb2[i];
        if (B[i]=='A')
            suma2[i+1]++;
        else sumb2[i+1]++;
    }
}
void solve()
{
    int q,a,b,c,d;
    cin>>q;
    _for(i,0,q)
    {
        cin>>a>>b>>c>>d;
        int ta1=suma1[b] - suma1[a-1],tb1=sumb1[b] - sumb1[a-1];
        int ta2=suma2[d] - suma2[c-1], tb2=sumb2[d] - sumb2[c-1];
        if ((ta1 + tb1*2)%3==(ta2+tb2*2)%3) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    enter();
    solve();
}
