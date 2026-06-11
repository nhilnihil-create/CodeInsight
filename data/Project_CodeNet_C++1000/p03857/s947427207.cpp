#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define tam 220010
#define offset 220010
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> ii;
typedef pair<double,double> iib;
typedef pair<ll,ii> iii;
typedef pair<map<ll,ll> ,ll> mi;
typedef pair<ii,ii> iiii;
typedef vector<ll> vi;
int findpa(int num,vector<int> &arrpa)
{
    if (arrpa[num]==num)
        return num;
    else return arrpa[num]=findpa(arrpa[num],arrpa);
}
ll cant[tam],ans[tam];
vector<int> grafo[tam];
int  main()
{
    int N,K,L;
    cin>>N>>K>>L;
    int iz,der;
    int pa1,pa2;
    vector<int> arrpa1(N),arrpa2(N);
    forr(i,0,N)
    arrpa2[i]=arrpa1[i]=i;
    forr(i,0,K)
    {
        cin>>iz>>der;iz--,der--;
        pa1=findpa(iz,arrpa1);
        pa2=findpa(der,arrpa1);
        arrpa1[pa1]=pa2;
    }
    forr(i,0,L)
    {
        cin>>iz>>der;iz--,der--;
            pa1=findpa(iz,arrpa2);
            pa2=findpa(der,arrpa2);
        arrpa2[pa1]=pa2;
    }
    forr(i,0,N)
    {
        grafo[findpa(i,arrpa1)].pb(i);
    }
    memset(cant,0,sizeof cant);
    int nodo;
    forr(i,0,N)
    {
        forr(j,0,grafo[i].size())
        {
            nodo=grafo[i][j];
            cant[findpa(nodo,arrpa2)]++;
        }
        forr(j,0,grafo[i].size())
        {
            nodo=grafo[i][j];
            ans[nodo]=cant[findpa(nodo,arrpa2)];
        }
        forr(j,0,grafo[i].size())
            nodo=grafo[i][j],cant[findpa(nodo,arrpa2)]=0;
    }
    forr(i,0,N)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}