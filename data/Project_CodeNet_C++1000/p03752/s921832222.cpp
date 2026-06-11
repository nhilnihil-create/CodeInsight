/*
2020/7/15
ロジックは組めるけど実装どうやるんだろ
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int N,K;
    cin >> N >> K ;
    vll a(N);
    for(int i=0;i<N;i++) cin >> a[i];
    ll ans=1e18;
    for(int i=0;i<(1<<N);i++){
        ll temp=i;
        int count=0;
        for(int j=0;j<N;j++){
            if(temp%2==1) count++;
            temp/=2;
        }
        if(count!=K) continue;
        vll building;
        ll temp2=i;
        for(int j=0;j<N;j++){
            if(temp2%2==1){
                building.push_back(j);
            }
            temp2/=2;
        }
        ll temp_ans=0;
        ll now_max=a[0];
        int j=0;
        for(int i=0;i<N;i++){
            if(now_max<a[i]) now_max=a[i];
            if(i==building[j]){
                if(now_max>=a[i]){
                    temp_ans+=now_max-a[i];
                    now_max++;
                    j++;
                }
            }
        }
        ans=min(ans,temp_ans);
    }
    cout << ans << endl;
    
}