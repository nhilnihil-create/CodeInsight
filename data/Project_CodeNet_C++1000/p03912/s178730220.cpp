#include <bits/stdc++.h>
using namespace std;

const int MAX = 100100;

int N, M;
vector<int> X;
vector<int> mod, modc, modd;
int counts[MAX];
// pair countを取る

int main(){
    cin >> N >> M;
    X.resize(N);
    for(auto &v: X)
        cin >> v;
    
    mod.resize(M);
    modc.resize(M);
    modd.resize(M);
    
    for(int i=0; i<N; i++){
        mod[X[i]%M]++;
        counts[X[i]]++;
    }
    for(int i=0; i<MAX; i++){
        modc[i%M] += counts[i]/2 * 2;
        modd[i%M] += counts[i]%2;
    }
    int ans = 0;
    for(int i=0; i<=M/2; i++){
        if(i == M-i || i == 0){
            ans += mod[i]/2;
        }else{
            int s = min(mod[i], mod[M-i]);
            ans += s;
        
            int t;
            
            t = max(0, s - modd[i]);
            ans += max(0, modc[i] - t) / 2;
            
            t = max(0, s - modd[M-i]);
            ans += max(0, modc[M-i] - t) / 2;
        }
    }
    cout << ans << endl;
    
    return 0;
}