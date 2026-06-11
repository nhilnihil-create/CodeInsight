#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

vector<int> e[2100];

int dfs(int s, int prev, int k, int d){
    int res = 0;
    if(d > k){
        res++;
    }
    for(auto v: e[s]){
        if(v == prev){
            continue;
        }
        res += dfs(v, s, k, d+1);
    }
    return res;
}

int main(){
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int res = INT32_MAX;
    for(int i = 0; i < N; i++){
        if(K % 2 == 0){
            res = min(res, dfs(i, -1, K/2, 0));
        }
        else{
            for(auto v: e[i]){
                if(i > v){
                    continue;
                }
                int res1 = dfs(i, v, (K-1)/2, 0);
                int res2 = dfs(v, i, (K-1)/2, 0);
                res = min(res, res1+res2);
            }
        }
    }

    cout << res << endl;



    return 0;
}
