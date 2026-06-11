#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll  INF = ll(1e18)+5;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if(a[0] +1 <a.back()){
        cout <<"No" << endl;
        return 0;
    }
    if(a[0] == a.back()){
        if(a[0] == N-1 || a[0] <=N/2){
            cout <<"Yes" << endl;
            return 0;
        }
        cout <<"No" << endl;
        return 0;        
    }
    ll repeated =0;
    for(int i=1;i<N;i++){
        if(a[i] == a[0]){
            repeated++;
        }
    }

    
    if((a[0]-repeated) * 2 <= N-repeated-1 && a[0]>repeated && repeated+1<N-1){
        cout <<"Yes" << endl;
        return 0;
    }
    
    cout <<"No" << endl;

    return 0;
}