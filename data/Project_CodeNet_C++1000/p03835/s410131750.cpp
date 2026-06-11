#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int K,S;
    cin >> K >> S;
    
    int ans=0;
    for(int i=0; i<=K; i++){
        for(int j=0; j<=K; j++){
            if(i+j > S) break;
            
            if(S-(i+j)<=K){
                ans++;
            }
        }
    }
    cout << ans << endl;

}
