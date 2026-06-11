#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    int ans = 1;
    for(int i = 0; i < N; i++){
        if(i == 0){
            ans *= K;
        }
        else{
            ans *= (K - 1);
        }
    }
    cout << ans << endl;
    return 0;
}