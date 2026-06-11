#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl
#define debug false


signed main(void){
    int N,a;
    vector<int> A;
    cin >> N;
    REP(i,N){
        cin >> a;
        A.push_back(a);
    }
    
    int Ans=INF;
    int num=0;
    int sum=0;
    REP(i,N){
        sum+=A[i];
        if(i%2==0 && sum<=0){
            num+=1-sum;
            sum=1;
        }else if(i%2==1 && sum>=0){
            num+=sum+1;
            sum=-1;
        }
    }
    Ans=num;
    
    num=0;
    sum=0;
    REP(i,N){
        sum+=A[i];
        if(i%2==1 && sum<=0){
            num+=1-sum;
            sum=1;
        }else if(i%2==0 && sum>=0){
            num+=sum+1;
            sum=-1;
        }
    }
    Ans=min(Ans,num);
    cout << Ans << endl;
    return 0;
}

