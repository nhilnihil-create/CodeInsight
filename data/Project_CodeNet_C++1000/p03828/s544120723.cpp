#include<iostream>
#include<array>

using namespace std;

int main(){
    int n, t, tmp, ans = 1;
    array<int, 1001> so;

    cin >> n;
    so.fill(0);

    for(int i = 2; i <= n; i++){
        tmp = i;
        t = 2;
        while(tmp != 1){
            if(tmp % t == 0){
                so[t]++;
                tmp /= t;
            }else{
                t++;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(so[i] != 0){
            t = ans;
            if(ans >= 1000000007 / (so[i] + 1) ){
               for(int k = 0; k < so[i]; k++){
                    ans += t;
                    if(ans >= 1000000007) ans -= 1000000007;
                }
            }else{
                ans *= so[i] + 1;
            }
        }
    }

    cout << ans << endl;
}