#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ff first
#define ss second
#define sf ss.ff
#define tt ss.ss
#define input(a) scanf("%lld",&a)
#define M 1000000007
#define inf 1<<30
#define DIN freopen("input.txt","r",stdin);
#define DOUT freopen("output.txt","w",stdout);

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

/*
 *Use abbreviation:
 *dsu ->Disjoint Set Union
 *bit ->Binary Indexed Tree
 *math ->Mathematical Functions(gcd,fact,bigMod,ncr)
 *test ->For test cases
 */

ll n,ara[300010],res;

int main()
{
    cin>>n;
    for(int i=0;i<3*n;i++)
        scanf("%lld",&ara[i]);
    sort(ara,ara+3*n);
    res=0;
    for(int i=3*n-1,j=0;j<2*n;i--,j++){
        //cout<<ara[i]<<endl;
        if(j&1)
            res+=ara[i];
    }
    cout<<res<<endl;
    return 0;
}

