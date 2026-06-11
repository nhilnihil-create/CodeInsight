#include <bits/stdc++.h>

using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, n) for (int i = 1; i < (int)(n+1); i++)
#define rep4(i, s, n) for (int i = (s); i < (int)(n+1); i++)
#define repr(i,n) for (int i = (n-1); i>=0;i--)
#define repr2(i,s,n) for (int i = (n-1); i>=(int)(s);i--)
#define repr3(i,n) for(int i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
const ll INF = 1001001000100010;
const ld PI = 3.14159265358979323846;


int main() {
int N,K;

cin>>N>>K;
ll B[20];
rep(i,N){
    cin>>B[i];

}
ll memo=0,cost=0,min_cost=INF,count=0;
rep(i,1<<N){
    memo=0;
    cost=0;
    count=0;
    rep(j,N){
        if((i>>j)&1){
            memo=max(memo+1,B[j]);
            cost+=max(memo,B[j])-B[j];
            count++;
        }
        else{
            if(B[j]>memo){
            memo=B[j];
            count++;
            }
        }
    }
    if(count==K){
    min_cost=min(min_cost,cost);
    }

}
cout<<min_cost<<endl;
return 0;
}

