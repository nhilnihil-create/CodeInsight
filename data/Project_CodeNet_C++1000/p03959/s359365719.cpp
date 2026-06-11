#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = ll(1e9)+7;

int main(){
    ll N;
    cin >> N;
    set<ll> detected;
    vector<ll> T(N);
    detected.insert(0);
    for(int i=0;i<N;i++){
        cin >> T[i];
        if(i>0&&T[i]>T[i-1]){
            detected.insert(i);
        }
    }
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
        if(detected.find(i) != detected.end() && T[i] >A[i]){
            cout << 0 << endl;
            return 0;
        }
    }
    if(A[N-1] >T[N-1]){
        cout << 0 << endl;
        return 0;
    }
    detected.insert(N-1);
    
    vector<ll> mAT(N);
    for(int i=0;i<N-1;i++){
        if(A[i]>A[i+1]){
            if(A[i] > T[i]){
                cout << 0 << endl;
                return 0;
            }
            detected.insert(i);
        }
        mAT[i] = min(A[i],T[i]);
        // cerr << mAT[i]<< endl;
    }
    
    ll ans =1;
    for(int i=0;i<N;i++){
        if(detected.find(i) == detected.end()){
            ans *= mAT[i];
            ans %= MOD;
        }else{
            // cerr <<"detected"<< endl;
        }
    }
    cout<< ans << endl;




    return 0;
}