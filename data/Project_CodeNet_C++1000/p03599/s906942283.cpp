#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999999;



int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    a*=100;
    b*=100;
    int ans1=0;
    int ans2=0;
    ld maxcon=-1;
    for(int A=0;A*a<=f;A++){
        for(int B=0;B*b<=f;B++){
            int water=A*a+B*b;
            if(water==0 || water>f) continue;
            int maxsuger=water/100*e;
            for(int C=0;C*c<=maxsuger;C++){
                for(int D=0;D*d<=maxsuger;D++){
                    int suger=C*c+D*d;
                    if(water+suger>f) continue;
                    if(suger>maxsuger) continue;
                    if(maxcon<(ld)suger/water){
                        maxcon=(ld)suger/water;
                        //cout<<maxcon<<endl;
                        ans1=water+suger;
                        ans2=suger;
                    }
                }
            }

        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    
}