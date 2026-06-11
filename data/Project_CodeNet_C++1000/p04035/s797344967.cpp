#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,L;
    cin >> N >> L;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    ll l=-1,r=-1;
    for(int i=1;i<N;i++){
        if(A[i-1]+A[i]>=L){
            l = i-1;
            r=i;
            break;
        }
    }
    if(l==-1){
        cout << "Impossible" << endl;
        return 0;
    }
    cout <<"Possible" << endl;
    for(int i=0;i<l;i++){
        cout << i+1 << endl;
    }
    for(int j=N-1;j>r;--j){
        cout << j << endl;
    }
    cout << r << endl;


    return 0;
}