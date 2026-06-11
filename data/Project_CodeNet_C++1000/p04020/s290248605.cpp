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

ll n,sm,x,res;

int main()
{
    cin>>n;
    res=sm=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x){
            sm+=x;
        }
        else{
            res+=sm/2;
            sm=0;
        }
    }
    cout<<res+sm/2<<endl;
    return 0;
}

