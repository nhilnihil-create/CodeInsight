//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
LL T[100000],A[100000];

LL ans = 1;

void solve(){
    //i番目の山の高さが
    //1~HまでのH種類ありうるときheight_cand_T[i] = Hとする
    //絶対にHのみしかあり得ない時はheight_cand_T[i] = -Hとする
    vector<LL> height_cand_T(N);
    height_cand_T[0] = -T[0];
    for(int i=1;i<N;i++){
        if(T[i]==T[i-1]) height_cand_T[i] = T[i];
        else height_cand_T[i] = -T[i];
    }

    //同様にheight_cand_Aを定義
    vector<LL> height_cand_A(N);
    height_cand_A[N-1] = -A[N-1];
    for(int i=N-2;i>=0;i--){
        if(A[i]==A[i+1]) height_cand_A[i] = A[i];
        else height_cand_A[i] = -A[i];
    }

    for(int i=0;i<N;i++){
        if(height_cand_T[i]<0){
            LL fixed_height = -height_cand_T[i];
            if(height_cand_A[i]<0){
                if(height_cand_T[i]!=height_cand_A[i]){
                    ans = 0;
                    return;
                }
            }else{
                if(fixed_height>height_cand_A[i]){
                    ans = 0;
                    return;
                }
            }
        }else{
            if(height_cand_A[i]<0){
                LL fixed_height = -height_cand_A[i];
                if(fixed_height>height_cand_T[i]){
                    ans = 0;
                    return;
                }
            }else{
                ans = (ans*min(height_cand_A[i],height_cand_T[i]))%mod;
            }
        }
    }
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> T[i];
    for(int i=0;i<N;i++) cin >> A[i];
 
    solve();

    cout << ans << endl;
    return 0;
}