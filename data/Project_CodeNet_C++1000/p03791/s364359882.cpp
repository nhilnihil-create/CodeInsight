#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef long double LD;
typedef pair<LD, LD> PLDLD;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define ALL(a) a.begin(),a.end()

LL MOD=1000000007;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n)   
        cin>>a[i];
    LL sum=1;
    int muri=0;
    REP(i,n)
    {
        if(i==0)continue;
        
        if(i==1)
        {
            sum*=2;
            if(a[i]<3)muri++;
            continue;
        }

        sum*=i+1-muri;
        sum%=MOD;
        muri=max(muri, ((i+1)*2-1 - a[i] +1)/2);
    }

    cout<<sum<<endl;
}
