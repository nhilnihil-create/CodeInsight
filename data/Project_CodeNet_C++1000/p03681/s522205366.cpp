#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    ll N, M;
    cin>>N>>M;
    ll ln = pow(10,9)+7;
    //abs(N-M)>1のときは並べ方がないのでおしまい
    if(abs(N-M)>1){
        cout<<0<<endl;
    }else if(N==M){
        //この時には左端にサルと犬の両方が来ることになる。
        ll dog_combi=1;
        rep(i,N+1){
            if (i==0)continue;
            dog_combi = dog_combi*i%ln;
        }
        ll output = (dog_combi*dog_combi*2)%ln;
        cout<<output<<endl;
    }else{
        ll dog_combi=1;
        rep(i,N+1){
            if (i==0)continue;
            dog_combi = dog_combi*i%ln;
        }
        ll monkey_combi=1;
        rep(i,M+1){
            if (i==0)continue;
            monkey_combi =monkey_combi*i%ln;
        }
        ll output = dog_combi*monkey_combi%ln;
        cout<<output<<endl;

    }


return 0;

}
