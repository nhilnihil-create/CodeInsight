#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    for(int bit=0;bit<(1<<2);++bit){
        vector<bool> isSheep(N,false);
        for(int i=0;i<2;i++){
            if((bit>>i) &1){
                isSheep[i] = true;
            }
        }
        for(int i=1;i<N-1;i++){
            if(isSheep[i]){
                if(S[i] == 'o'){
                    isSheep[i+1] = isSheep[i-1];
                }else{
                    isSheep[i+1] = !isSheep[i-1];
                }
            }else{
                if(S[i] == 'x'){
                    isSheep[i+1] = isSheep[i-1];
                }else{
                    isSheep[i+1] = !isSheep[i-1];
                }
            }
        }
        bool ok = true;
        for(int i=0;i<2;i++){
            int t = (N-1+i)%N;
            int next = (N+i)%N;
            int prev = (N-2+i)%N;
        if(isSheep[t]){
            if(S[t] == 'o'){
                if(isSheep[next] != isSheep[prev]){
                   ok = false;
                }
            }else{
                if(isSheep[next] == isSheep[prev]){
                    ok = false;
                }
            }
        }else{
            if(S[t] == 'o'){
                if(isSheep[next] == isSheep[prev]){
                    ok = false;
                }
            }else{
                if(isSheep[next] != isSheep[prev]){
                    ok = false;
                }
            }
        }
        }
        if(!ok){
            continue;
        }
        for(int i=0;i<N;i++){
            if(isSheep[i]){
                cout <<"S";
            }else{
                cout <<"W";
            }
        }
        cout <<endl;
        return 0;
    }

    cout << -1 << endl;

    return 0;
}