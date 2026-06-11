/**
*    author:  yuya1234
*    created: 26.06.2020 13:30:29
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    double ee=100*(double)e/(100+e);

    vector<int> v;

    REP(i,f-i*100*a+1)
    {
        REP(j,f-i*100*a-j*b*100+1)
        {
            v.push_back((i*a+j*b)*100);
        }
    }

    SORT(v);
    UNIQUE(v);

    int ansAB=v[1],ansB=0,sumA=0,sumB=0;
    double sumN=0.0,ansMax=0.0;

    FOR(i,1,SZ(v)-1)
    {
        sumA=v[i];
        REP(j,f-sumA+1)
        {
            REP(k,f-sumA+1)
            {
                sumB=j*c+k*d;
                if(sumB==0)continue;
                sumN=100*(double)sumB/(sumA+sumB);
                if(ee>=sumN && f>=sumA+sumB)
                {
                    if(ansMax<sumN)
                    {
                        ansAB=sumA+sumB;
                        ansB=sumB;
                        ansMax=sumN;
                        k=0;
                    }
                }
                else break;
            }
        }
    }

    cout<<ansAB<<" "<<ansB<<endl;

    return 0;
}