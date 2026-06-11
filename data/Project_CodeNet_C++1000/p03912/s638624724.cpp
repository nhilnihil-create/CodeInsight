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

lli odd[100100];
lli even[100100];
lli cnt[100100];

void func(long long N, long long M, std::vector<long long> X){

    REP(i,0,N){
        cnt[X[i]]++;
    }

    REP(i,0,100100){
        even[i%M]+= cnt[i]%2;
        odd[i%M] += (cnt[i]/2)*2;
    }

    //0は先に処理する
    lli ans = 0;
    ans += even[0]/2+odd[0]/2;

    //Mが偶数の場合、m/2が厄介なのでこれも処理する。
    if(M%2==0)ans += even[M/2]/2 + odd[M/2]/2;

    REP(i,0,M/2+1){
        if(i==0 || (M%2==0 && i==M/2))continue;
        if(DEBUG)cout<<"i="<<i<<endl;
        //相手同士でマッチングさせる
        if(even[i]>even[M-i]){
            swap(even[i],even[M-i]);
            swap(odd[i],odd[M-i]);
        }

        ans += even[i];
        even[M-i]-=even[i];
        even[i]=0;

        //余ったeven[M-i]をoddにマッチングさせられるか？
        lli tmp = min(odd[i],even[M-i]);
        if(DEBUG)cout<<"tmp="<<tmp<<endl;
        odd[i]-=tmp;
        even[M-i]-=tmp;
        ans += tmp;

        ans += odd[i]/2;
        ans += odd[M-i]/2;
    }
    cout<<ans<<endl;


}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> X(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&X[i]);
    }
    func(N, M, std::move(X));
    return 0;
}
