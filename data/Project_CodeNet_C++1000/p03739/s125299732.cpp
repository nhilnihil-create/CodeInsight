#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF =ll(1e18)+5;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    ll ans = INF;
    {
        //正負と続いていくもの
        ll sum =0;
        ll temp =0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(i%2==0){
                if(sum<=0){
                    temp += (1-sum);
                    sum =1;
                }
            }else{
                if(sum>=0){
                    temp += (sum+1);
                    sum =-1;
                }
            }
        }
        ans = min(ans,temp);


    }
    {
        //逆
        ll sum =0;
        ll temp =0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(i%2==1){
                if(sum<=0){
                    temp += (1-sum);
                    sum = 1;
                }
            }else{
                if(sum>=0){
                    temp += (sum+1);
                    sum = -1;
                }
            }
        }
        ans = min(ans,temp);
    }
    cout << ans << endl;

    return 0;
}