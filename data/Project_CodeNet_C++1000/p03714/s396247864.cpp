#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define ld PRId64
#define n_max int(1e5)


int main(){
    int n;
    cin >>n;
    llong A[3*n_max +5];
    REP(i,3*n) scanf("%lld" , &A[i]);

    llong ma[n_max +3],mi[n_max+3];
    ma[0]=0;
    mi[0]=0;

    priority_queue<llong,vector<llong>,greater<llong>> Que;
    REP(i,n){
        ma[0]+=A[i];
        Que.push(A[i]);
    }

    REP(i,n){
        if(Que.top() < A[n+i]){
            ma[i+1]= ma[i] - Que.top() + A[n+i];
            Que.pop();
            Que.push(A[n+i]);
        }
        else ma[i+1] = ma[i];
    }

    reverse(A,A+3*n);
    priority_queue<llong> Que1;
    REP(i,n){
        mi[0]+=A[i];
        Que1.push(A[i]);
    }





    REP(i,n){
        if(Que1.top() > A[n+i]){
            mi[i+1]= mi[i] - Que1.top() + A[n+i];
            Que1.pop();
            Que1.push(A[n+i]);
        }
        else mi[i+1] = mi[i];
    }

    llong ans=ma[n] - mi[0];
    FOR(i,1,n+1){
        if(ans < ma[n-i] - mi[i]) ans = ma[n-i] - mi[i];
    } 

    cout << ans << endl;


}