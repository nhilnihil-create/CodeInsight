#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
 
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define LLIandI pair<long long int , int>
/*
 1≤N≤10^5
1≤L≤10^9
1≤T≤10^9
0≤X1<X2<…<XN≤L−1
1≤Wi≤2
Wi が 1 なら時計回りに、Wi が 2 なら反時計回りに動き始めます
v=1
 */
 
int main(){
    long long int N,L,T;
    scanf("%lld %lld %lld",&N,&L,&T);
    long long int X[100002],W[100002];
    vector<long long int> hit_one;
    rep(i,N){
        scanf("%lld %lld",&X[i],&W[i]);
        if(W[i]==1)W[i]=+1;
        if(W[i]==2)W[i]=-1;
        if(W[i]*W[0]<0)hit_one.push_back(i);
    }
    long long int list_ans[100002];
    rep(i,N){
        long long miniT=T%L;
        list_ans[i]=( ( (X[i]+W[i]*miniT)%L)+L)%L;
    }
    long long int zero_to_what=0;//0だと思われている座標は実際にはzero_to_what
    rep(i,hit_one.size()){
        long long int kyori;
        if(W[0]==1)kyori=abs(X[hit_one[i]]-X[0]);
        else kyori=X[0]+(L-X[hit_one[i]]);
        if(2*T>=kyori)zero_to_what+= ( ((2*T-kyori)/L)+1 );
    }
    zero_to_what=( (zero_to_what%N*W[0])+N)%N;
    long long int zero_to_what_x=list_ans[0];//0だと思われているが実際にはzero_to_whatであるものの座標
    sort(list_ans,list_ans+N);
    zero_to_what_x=lower_bound(list_ans,list_ans+N,zero_to_what_x)-list_ans;//zero_to_what_xのindex
if(zero_to_what_x<N&&list_ans[zero_to_what_x]==list_ans[(zero_to_what_x+1)%N]){
if(W[0]>0)zero_to_what_x=(zero_to_what_x+1)%N;
}
    //つまりzero_to_what+iの座標はlist_ans[zero_to_what_x+i]
    rep(i,N){
        printf("%lld\n",list_ans[(zero_to_what_x+i-zero_to_what+N)%N]);
    }
   
}
