#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,K;
    cin >> N >> K;
    vector<int> d(K);
    for(int i = 0; i < K;i++)cin >> d[i];
    
    for(int i = N; N < 10000; i++){
        
        int M = i;
        bool flag = false;
        while(M){
            
            int A = M % 10;
            for(auto a:d){
                if(A==a)flag = true;
            }
            
            M/= 10;
            
        }
        
        if(flag)continue;
        cout << i << endl;
        return 0;
    }
}
