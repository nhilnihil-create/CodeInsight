/**
*    author:  yuya1234
*    created: 25.06.2020 14:29:35
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

    int w,h,n;
    cin>>w>>h>>n;

    int tx,ty,ta;
    int d[4]={0,0,w,h};

    REP(i,n)
    {
        cin>>tx>>ty>>ta;
        switch (ta)
        {
        case 1:
            if(d[0]<tx)d[0]=tx;
            break;
        case 2:
            if(d[2]>tx)d[2]=tx;
            break;
        case 3:
            if(d[1]<ty)d[1]=ty;
            break;
        case 4:
            if(d[3]>ty)d[3]=ty;
            break;
        }
    }
    
    if(d[0]<d[2] && d[1]<d[3])
    {
        cout<<(d[2]-d[0])*(d[3]-d[1])<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    


    return 0;
}