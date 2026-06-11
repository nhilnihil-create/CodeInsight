#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE cout << -1 << endl;return 0
#define Endl endl

signed main(void){
    int N,X;
    cin >> N >> X;
    int Ans=N;
    
    int a=N-X,b=X;
    if(a>b)swap(a,b);
    while(1){
        
        Ans+=2*a*((int)(b/a)-1);
        b=a+b%a;
        if(a==1){
            Ans+=2*b-1;
            break;
        }
        if(a==b){
            Ans+=a;
            break;
        }
        Ans+=2*a;
        b-=a;
        if(a>b)swap(a,b);
        
        if(a==1){
            Ans+=2*b-1;
            break;
        }
    }
    cout << Ans << endl;
    return 0;
}



