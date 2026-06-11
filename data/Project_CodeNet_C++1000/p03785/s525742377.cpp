#include <bits/stdc++.h>
using namespace std;


int main(void){
 
    int N;
    long long C,K;
    cin >> N >> C >> K;
    long long T[N];
    for(long long i = 0; i < N;i++){
        cin >> T[i];
    }
    
    sort(T,T+N);
    
    long long ans = 0;

    for(long long i = 0; i < N;){
        ans++;
        long long start = i;
        while(i < N&& i - start < C&&T[i] - T[start] <= K)i++;
        
    }

    
    cout << ans << endl;
    
}