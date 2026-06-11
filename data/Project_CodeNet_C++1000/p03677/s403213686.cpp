#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N, M;
int A[100000];
ll cost1[100001] ={}, cost2[100001]={};

signed main(){
    cin >> N >> M;
    rep(i, N){
        cin >> A[i];
        A[i]--;
    }
    
    rep(i, N-1){
        cost1[0] += (M+A[i+1] - A[i]) % M;
        cost1[M] -= (M+A[i+1] - A[i]) % M;
        if(A[i] < A[i+1]){
            cost2[A[i]+1]++;
            cost2[A[i+1]+1]--;
            cost1[A[i]+1] += A[i]+1;
            cost1[A[i+1]+1] -= A[i]+1;
        }
        else{
            cost2[A[i]+1]++;
            cost2[M]--;
            cost1[A[i]+1] += A[i]+1;
            cost1[M] -= A[i]+1;

            cost2[0]++;
            cost2[A[i+1]+1]--;
            cost1[0] -= M-A[i]-1;
            cost1[A[i+1]+1] += M-A[i]-1;
        }
    }

    ll ans = LLONG_MAX;
    rep(i, M){
        cost1[i+1] += cost1[i];
        cost2[i+1] += cost2[i];
        //cout << cost1[i] << " " << cost2[i] << " " << cost1[i]-i*cost2[i] <<  endl;
        ans = min(ans, cost1[i]-i*cost2[i]);
    }
    cout << ans << endl;
}