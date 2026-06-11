#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    long long p = 1;
    for(int i = 1; i <= N; i++){
        if(i==1){
            p *= K;
        }else{
            p *= (K - 1);
        }
        if(p>INT32_MAX){
            p = INT32_MAX;
            break;
        }
    }
    cout << p;
    return 0;
}