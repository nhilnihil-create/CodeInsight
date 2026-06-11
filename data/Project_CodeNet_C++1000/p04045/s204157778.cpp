#include <iostream>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    int d[K];
    for(int i = 0; i < K; i++) cin >> d[i];
    int ans = N;
    while(1){
        int res = ans;
        int flag = 0;
        while(res > 0){
            int a = res % 10;
            for(int i = 0; i < K; i++){
                if(a == d[i]){
                    flag = 1;
                }
            }
            res /= 10;
        }
        if(flag == 0) break;
        ans++;
    }
    cout << ans << endl;
}