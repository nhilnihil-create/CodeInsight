#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n, x;
    cin >> n >> x;
    int ans[2*n-1];
    rep(i, 2 * n - 1) ans[i] = 0;
    if (x > 1 && x < 2 * n - 1){
        ans[n-1] = x;
        int idx = 1;
        if (x < n){
            for (int i = 1; i < x; i++){
                if (idx % 2 == 0){
                    ans[n-1-idx] = i;
                }else{
                    ans[n-1+idx] = i;
                }
                idx++;
            }
            idx = 0;
            for (int i = x + 1; i <= 2 * n - 1; i++){
                while(ans[idx] != 0){
                    idx++;
                }
                ans[idx] = i;
                idx++;
            }
        }else{
            for (int i = x + 1; i <= 2 * n - 1; i++){
                if (idx % 2 == 0){
                    ans[n-1-idx] = i;
                }else{
                    ans[n-1+idx] = i;
                }
                idx++;
            }
            idx = 0;
            for (int i = 1; i < x; i++){
                while(ans[idx] != 0){
                    idx++;
                }
                ans[idx] = i;
                idx++;
            }
        }
        cout << "Yes" << endl;
        rep(i, 2 * n - 1) cout << ans[i] << endl;
    }else cout << "No" << endl;
    
    
}
