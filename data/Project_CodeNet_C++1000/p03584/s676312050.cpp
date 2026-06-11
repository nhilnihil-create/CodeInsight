//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/tenka1-2017/tasks/tenka1_2017_d

//ポイント：
//OR = なるべくビットが立っていたほうが嬉しいという意識
 
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
#include <stack>
#include <map> 
#include <unordered_map> 
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

LL N,K;
LL A[100000],B[100000];

LL ans = 0;

LL val_sum(LL bit){
    LL ret = 0;
    for(int i=0;i<N;i++){
        bool ok = true;
        for(int j=0;j<30;j++){
            if(!((bit>>j)&1LL) && ((A[i]>>j)&1LL)) ok = false;
        }
        ret += ok*B[i];
    }
    return ret;
}

void solve(){
    ans = val_sum(K);
    for(int d=0;d<30;d++){
        //Kのd桁目が1なら
        if((K>>d)&1LL){
            LL wise = K;
            wise &= ~(1<<d);//d桁目を0に変える
            wise |= ((1<<d) - 1);//d-1桁目より下を1に変える
            ans = max(ans,val_sum(wise));
        }
    }
}
 
int main(){
	cin >> N >> K;
    for(int i=0;i<N;i++) cin >> A[i] >> B[i];
 
    solve();

	cout << ans << endl;
    return 0;
}