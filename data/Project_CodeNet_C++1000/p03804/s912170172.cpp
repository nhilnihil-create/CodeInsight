#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    int N,M;
    cin >> N >> M;
    string A[N];
    string B[M];
    for(int i = 0; i < N;i++)cin >> A[i];
    for(int i = 0; i < M;i++)cin >> B[i];
    
    bool flag;
    for(int i = 0; i <= N - M;i++){
        
        for(int j = 0; j <= N - M;j++){
        
            flag = true;
        
            for(int k = 0; k < M;k++){
                
                for(int l = 0; l < M;l++){
                    
                    if(A[i+k][j+l]!=B[k][l]){
                        flag = false;
                        break;
                    }
                    
                }
            if(!flag)break;
            }
            
            if(flag){
                cout << "Yes"<<endl;
                return 0;
            }    
        
        
        }
        
    }
    
    cout << "No"<<endl;
    return 0;

}
