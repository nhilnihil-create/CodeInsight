#include <bits/stdc++.h>
using namespace std;

int main(){
    long N,T;
    cin >> N >> T;
    vector<long> t(N);
    vector<long> t2(N-1);
    long ans = 0;
    for(long i = 0; i < N;i++){
        cin >> t.at(i);
    }
    for(long i = 0;i<N-1;i++){
        t2.at(i) = t.at(i+1)-t.at(i);
        if(t2.at(i) < T){
            ans = ans + T - t2.at(i);
        }
    }
    cout << N*T - ans << endl;
    
}
