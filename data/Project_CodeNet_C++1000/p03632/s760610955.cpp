#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    map<int,int> count;
    for(int i = A; i <= B; i++) count[i]++;
    for(int j = C; j <= D; j++) count[j]++;
    int m = 0;
    for(auto p : count){
        if(p.se == 2) m++;
    }
    cout << max(m - 1, 0) << endl;
}
