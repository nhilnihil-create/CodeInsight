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

ll n,a[100010],b[100010],k;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&a[i],&b[i]);
    k=0;
    for(int i=n-1;i>=0;i--){
        k+=((a[i]+k)%b[i])?(b[i]-(a[i]+k)%b[i]):0;
    }
    cout<<k<<endl;
    return 0;
}

