#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
#define FOR(i,a,b)   for(ll i = (a); i < (b); i++ )
#define REP(i, n)    FOR(i,0,n)
typedef pair< ll, ll >   cp2;
typedef pair< string, cp2 >   cp3;
#define fi first
#define se second
#define sec  se.fi
#define thr  se.se
const ll mod = 1000000007;
//              123456789


///////////////////////////////////////////////
//
//
///////////////////////////////////////////////

////////////////////////////////////////////////
////////////////////////////////////////////////

int N;
ll A[112345];

bool bef;
int ans;

int main(){
    
    cin>>N;
    REP( i, N ) cin>>A[i];
    
    sort( A, A+N );
    
    bef = true;
    
    ans = N;
    FOR( i, 1, N ){
        if( A[i] == A[i-1] ){
            if( bef ){
                ans-=2;
                bef = false;
            }
            else{
                bef = true;
            }
        }
        else{
            bef = true;
        }
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}
