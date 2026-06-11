#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
typedef long long int ll;
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
//#define EFOR(i,a,b) for (int i=(a);i<=(b);i++)
const ll MOD = (10*10*10*10*10*10*10*10*10+7);
ll N,a,b,ans=1
    ,X[100010];
stack<long long int> st;
int main(){
    scanf("%lld",&N);
/*    for(int i=0;i<N;i++){
        scanf("%lld",&X[i]);
    }*/
    for(ll i=1;i<=N;i++){
        scanf("%lld",&X[i]);
        st.push(X[i]);
        if(X[i]<2*st.size()-1){
            ans*=st.size();
            st.pop();
        }
        ans%=MOD;
    }
    for(ll i=1;i<=st.size();i++){
        ans*=i;
        ans%=MOD;
    }
    printf("%lld",ans);
    return 0;
}
