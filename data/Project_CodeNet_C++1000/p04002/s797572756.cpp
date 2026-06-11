#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define tam 200010
#define tamlog 12
#define offset 50000
#define mp make_pair
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> ii;
typedef pair<string,ll> si;
typedef pair<ll,ii> iii;
const ll INF=1e11;
ll H,W,N;
set<ii> resp[12];
set<ii> s;
ll hay(ll xx,ll yy)
{
    if (s.find(mp(xx,yy))==s.end())
        return 0;
    return 1;
}
bool valid(ll xx,ll yy)
{
    if (xx<=0|| yy<=0|| xx>H|| yy>W)
        return 0;
    return 1;
}
ll calc(ll xx,ll yy)
{
    ll tot=0;
    for(ll i=0;i>=-2;i--)
    {
        for(ll j=0;j>=-2;j--)
        {
            if (valid(xx+i,yy+j)==false)
                return 10;
            tot+=hay(xx+i,yy+j);
        }
    }
    return tot;
}
ll vx[tam],vy[tam];
int main()
{
    
    cin>>H>>W>>N;
    forr(i,0,N)
    {
        cin>>vx[i]>>vy[i];
        s.insert(ii(vx[i],vy[i]));
    }
    ll xx,yy;
    forr(i,0,N)
    {
        forr(j,0,3)
        {
            forr(k,0,3)
            {
                xx=vx[i]+j;
                yy=vy[i]+k;
                resp[calc(xx,yy)].insert(ii(xx,yy));

            }
        }
    }
    ll atot=0;
    forr(i,1,10)
    atot+=resp[i].size();
    cout<<(H-2)*(W-2)-atot<<endl;
    forr(i,1,10){
        cout<<resp[i].size()<<endl;
        /*for(set<ii>::iterator ite=resp[i].begin();ite!=resp[i].end();ite++)
        {
            //cout<<(*ite).fi<<" "<<(*ite).se<<endl;  
        }*/
    }

}
