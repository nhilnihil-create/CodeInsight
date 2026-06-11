#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.begin(),B.end());
    map<ll,int> mp;
    for(int i=0;i<N;i++){
        mp[B[i]] =i;
    }

    ll  canNotMove =0;
    for(int i=0;i<N;i++){
        int act = i;
        int ideal = mp[A[i]];
        // cerr <<"act=" << act << "ideal=" << ideal << endl;
        if(act%2 != ideal%2){
            canNotMove++;
        }
    }
    cout << canNotMove/2 << endl;


    return 0;
}