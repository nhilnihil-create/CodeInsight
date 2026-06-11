#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 1100000000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,ll> P;

const int MAX_C=100;
ll Com[MAX_C][MAX_C];
vector<int> V;

void calc_com(){
    memset(Com,0,sizeof(Com));
    Com[0][0]=1;
    for(int i=1;i<MAX_C;i++){
        Com[i][0]=1;
        for(int j=1;j<MAX_C;j++){
            Com[i][j]=Com[i-1][j-1]+Com[i-1][j];
        }
    }
}


int main(){
    calc_com();
    int N,A,B;
    cin>>N>>A>>B;
    ll v[60];
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    sort(v,v+N,greater<ll>());
    ll ans=0;

    for(int i=0;i<A;i++){
        ans+=v[i];
    }
    v[N]=0;
    int count=1;
    for(int i=1;i<=N;i++){
        if(v[i-1]==v[i]) count++;
        else{
            V.push_back(count);
            count=1;
        }
    }
    ll sum=0;
    if(V[0]>=A){
        for(int i=A;i<=min(B,V[0]);i++){
            sum+=Com[V[0]][i];
        }
    }else{
        int temp=0,num;
        for(int i=0;i<(int)V.size();i++){
            if(temp+V[i]>=A){
                num=i;
                break;
            }else temp+=V[i];
        }
        sum=Com[V[num]][A-temp];
    }
    printf("%.6lf\n",(double)ans/A);
    cout<<sum<<endl;
}
