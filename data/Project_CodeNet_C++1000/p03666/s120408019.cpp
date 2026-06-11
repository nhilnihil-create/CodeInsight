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
    int N;
    ll A,B,C,D,mi,pl;
    cin>>N>>A>>B>>C>>D;
    A-=B;
    N--;
    for(int i=0;i<=N;i++){
        pl=D*(N-i)+(-C)*i;
        mi=C*(N-i)+(-D)*i;
        //cout<<i<<" "<<mi<<" "<<pl<<endl;
        if(A>=mi && A<=pl){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}

