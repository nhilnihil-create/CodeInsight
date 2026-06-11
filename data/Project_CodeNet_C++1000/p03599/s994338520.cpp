#include <bits/stdc++.h>
using namespace std;
 
#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
 
 
void func(long long A, long long B, long long C, long long D, long long E, long long F){
    double deg = 0;
    lli ansW=100*A,ansS=0;
    for(lli a=0;100*a*A <= F;a++){
    for(lli b=0;100*(a*A+b*B)<=F;b++){
    for(lli c=0; (100*(a*A+b*B)+c*C <= F && c*C <= E*(a*A+b*B));c++){
    for(lli d=0; (100*(a*A+b*B)+c*C+d*D<=F && (c*C+d*D)<=E*(a*A+b*B)) ;d++){
        lli suger = c*C+d*D;
        lli water = 100*(a*A+b*B) + suger;
        if(suger==0)continue;
        if(water==0)continue;
        if(deg<(100*suger)/(double)(water)){
            deg = (100*suger)/(double)(water);
            ansW = water;
            ansS = suger;
        }
    }
    }
    }
    }
    cout<<ansW<<" "<<ansS<<endl;
}
 
int main(){
    // cout << fixed << setprecision(5);
 
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    long long D;
    scanf("%lld",&D);
    long long E;
    scanf("%lld",&E);
    long long F;
    scanf("%lld",&F);
    func(A, B, C, D, E, F);
    return 0;
}