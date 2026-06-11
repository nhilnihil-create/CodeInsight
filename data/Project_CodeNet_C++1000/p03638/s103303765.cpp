#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int H, W;
    cin >> H >> W;

    int N;
    cin >> N;

    int a[N];
    for(int i=0; i<N; i++) cin >> a[i];

    int ind = 0;
    int ans[H][W];
    for(int i=0; i<H; i++){
        if(i % 2 == 0){
            for(int j=0; j<W; j++){
                ans[i][j] = ind+1;
                a[ind]--;
                if(a[ind] == 0) ind++;
            }
        }else{
            for(int j=W-1; j>=0; j--){
                ans[i][j] = ind+1;
                a[ind]--;
                if(a[ind] == 0) ind++;
            }
        }
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
