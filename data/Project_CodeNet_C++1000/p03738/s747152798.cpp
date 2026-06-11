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
    string A, B;
    cin >> A >> B;
    int N = A.size();
    int M = B.size();
    if(N > M) puts("GREATER");
    else if(N < M) puts("LESS");
    else{
        if(A > B) puts("GREATER");
        else if(A < B) puts("LESS");
        else puts("EQUAL");
    }
}
