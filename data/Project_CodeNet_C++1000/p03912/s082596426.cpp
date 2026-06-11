#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef long double LD;
typedef pair<LD, int> PLDI;
typedef pair<LD, LD> PLDLD;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define ALL(a) a.begin(),a.end()
const int INF = (1e9);
const LL MOD = 1e9+7;
const double PI=atan2(0,-1);

    int bac[100001];
int main()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    vector<int> x(n);
    REP(i,n)
    {
        cin>>x[i];
        bac[x[i]%m]++;
    }
    sort(ALL(x));
    REP(i,m)
    {
        int cou;
        if(i!=0 && i!=m-i)
        {
            cou = min(bac[i], bac[m-i]);
            bac[i]-=cou;
            bac[m-i]-=cou;
        }
        else if(i==m-i)
        {
            cou=bac[i]/2;
            bac[i]-=cou*2;
        }
        else
        {
            cou=bac[i]/2;
            bac[i]-=cou*2;
        }
        
        ans+=cou;
    }
    
    REP(i,n-1)
    {
        if(x[i]==x[i+1])
        {
            if(bac[x[i]%m]>=2)
            {
                bac[x[i]%m]-=2;
                ans++;
                i++;
            }
        }
    }
    
    cout<<ans<<endl;
}