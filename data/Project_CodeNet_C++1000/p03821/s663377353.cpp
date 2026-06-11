#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    long long A[N],B[N];
    
    for(int i = 0; i < N;i++)cin >> A[i] >> B[i];
    
    
    long long cnt = 0;
    for(int i = N -1 ; i >= 0;i--){
        
        if((A[i]+cnt)%B[i]==0)continue;
        cnt += B[i] * ((A[i]+cnt)/B[i] + 1) - (A[i]+cnt);
        //cout << cnt << endl;
    }
    cout << cnt << endl;

}

    
    

