#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    int n; sc(n)
    vector<int> A(n);
    for (int i = 0; i < n; i++) sc(A[i])
    sort(A.begin(), A.end());
    int cnt = 0;
    for (int i = 0; i < n - 1; i++){
        if (A[i] == A[i + 1]) cnt += 1;
    }
    if (cnt % 2 == 1) cout << n - cnt - 1 << endl;
    else cout << n - cnt << endl;
    return 0;
}