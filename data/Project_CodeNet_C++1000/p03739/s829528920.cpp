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
vector<LL> A;

LL ans = INF;

void solve(){
    vector<LL> A_cpy(A);
    //正の数から開始
    {
        int sum = 0;
        LL counter = 0;
        for(int i=0;i<N;i++){
            //奇数回目では和が負なら良い
            if(i%2==1){
                if(sum+A_cpy[i]>=0){
                    counter += ((sum+A_cpy[i])+1);
                    A_cpy[i] = -(sum+1);
                }
                sum += A_cpy[i];
            }
            //偶数回目では和が正なら良い
            if(i%2==0){
                if(sum+A_cpy[i]<=0){
                    counter += (-(sum+A_cpy[i])+1);
                    A_cpy[i] = (-sum+1);
                }
                sum += A_cpy[i];
            }
        }
        // for(int i=0;i<N;i++){
        //     cout << A_cpy[i] << " ";
        // }
        // cout << endl;
        ans = min(ans,counter);
    }

    //負の数から開始
    {
        int sum = 0;
        LL counter = 0;
        for(int i=0;i<N;i++){
            //偶数回目では和が負なら良い
            if(i%2==0){
                if(sum+A[i]>=0){
                    counter += ((sum+A[i])+1);
                    A[i] = -(sum+1);
                }
                sum += A[i];
            }
            //奇数回目では和が正なら良い
            if(i%2==1){
                if(sum+A[i]<=0){
                    counter += (-(sum+A[i])+1);
                    A[i] = (-sum+1);
                }
                sum += A[i];
            }
        }
        // for(int i=0;i<N;i++){
        //     cout << A[i] << " ";
        // }
        // cout << endl;
        ans = min(ans,counter);
    }
}
 
int main(){
    cin >> N;
    A = vector<LL>(N);
    for(int i=0;i<N;i++) cin >> A[i];
 
    solve();

    cout << ans << endl;
    return 0;
}