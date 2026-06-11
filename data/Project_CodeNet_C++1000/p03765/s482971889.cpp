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

string S,T;
LL Q;
LL A[100000],B[100000],C[100000],D[100000];

vector<string> ans;

void solve(){
    //pair<それまで出てきたAの総数,それまで出てきたBの総数>
    vector<pair<LL,LL>> S_accum(S.size()+1,pair<LL,LL>(0,0));
    for(int i=0;i<S.size();i++){
        S_accum[i+1].first = S_accum[i].first + (S[i]=='A');
        S_accum[i+1].second = S_accum[i].second + (S[i]=='B');
    }
    vector<pair<LL,LL>> T_accum(T.size()+1,pair<LL,LL>(0,0));
    for(int i=0;i<T.size();i++){
        T_accum[i+1].first = T_accum[i].first + (T[i]=='A');
        T_accum[i+1].second = T_accum[i].second + (T[i]=='B');
    }

    for(int i=0;i<Q;i++){
        LL S_A = (S_accum[B[i]].first-S_accum[A[i]-1].first)%3LL;
        LL S_B = (S_accum[B[i]].second-S_accum[A[i]-1].second)%3LL;
        LL T_A = (T_accum[D[i]].first-T_accum[C[i]-1].first)%3LL;
        LL T_B = (T_accum[D[i]].second-T_accum[C[i]-1].second)%3LL;
        
        bool ok = false;
        for(int i=0;i<3;i++){
            if(S_A==(T_A+i)%3 && S_B==(T_B+i)%3) ok = true;
        }
        if(ok) ans.push_back("YES");
        else ans.push_back("NO");
    }
}
 
int main(){
	cin >> S >> T >> Q;
    for(int i=0;i<Q;i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
 
    solve();

	for(int i=0;i<Q;i++) cout << ans[i] << endl;
    return 0;
}