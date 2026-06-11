#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> P;
typedef pair<ll,pair<ll,ll>> p;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
static const int MAX_SIZE = 1 << 17; //segment tree のサイズ。この実装では2べきにする必要がある。 2^17 ≒ 1.3 * 10^5

int C[30];

int main(){
    bool flagT[110000],flagA[110000];
    ll A[110000],T[110000];
    int N;
    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>T[i];
    }

    for(int i=1;i<=N;i++){
        cin>>A[i];
    }

    for(int i=2;i<=N;i++){
        if(T[i]>T[i-1]) flagT[i]=true;
        else flagT[i]=false;
    }

    for(int i=N-1;i>=1;i--){
        if(A[i]>A[i+1]) flagA[i]=true;
        else flagA[i]=false;
    }

    flagT[1]=true;
    flagA[N]=true;
    ll ans=1;
    for(int i=1;i<=N;i++,ans%=MOD){
        if(flagA[i] && flagT[i]){
            if(A[i]!=T[i]){
                cout<<0<<endl;
                return 0;
            }
        }else if(!flagA[i] && !flagT[i]){
            ans*=min(A[i],T[i]);
        }else{
            if(flagA[i] && A[i]>T[i] || flagT[i] && T[i]>A[i]){
                cout<<0<<endl;
                return 0;
            }
        }
    }
    cout<<ans<<endl;
}

