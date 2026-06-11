
#include<bits/stdc++.h>
using namespace std;
#define itn int

int main(void){
    long long int x[2],y[2];
    cin >> x[0] >> y[0];
    
    x[1] = -x[0],y[1] = -y[0];
    
    long long int ans = -1;
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            if(x[i] <= y[j]){
                long long int num = (i+j) + (y[j]-x[i]);
                
                if(ans == -1)ans = num;
                else ans = min(ans,num);
            }
        }
    }
    cout << ans << endl;
}