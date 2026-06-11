#include <iostream>
#include <map>
using namespace std;

long dp[10];
int main() {
    int H, W, N;
    cin >> H >> W >> N;
    dp[0]=(long) (H-2)*(W-2);
    map<int, map<int, int>> mp;
    for(int c=0; c<N; c++){
        int a, b; cin >> a >> b;
        for(int i=max(a-2, 1); i<=min(a, H-2); ++i){
            for(int j=max(b-2, 1); j<=min(b, W-2); ++j){
                int cnt=0;
                for(int k=0; k<9; ++k) cnt += mp[i+k/3][j+k%3];
                --dp[cnt];
                ++dp[cnt+1];
            }
        }
        mp[a][b]=1;
    }
    for(int i=0; i<10; ++i) cout << dp[i] << endl;
    return 0;
}
