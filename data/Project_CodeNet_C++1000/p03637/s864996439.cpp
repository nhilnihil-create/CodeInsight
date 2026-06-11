#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    int n; sc(n)
    int A[n];
    for (int i = 0; i < n; i++) sc(A[i]);
    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; i++){
        if (A[i] % 2 != 0) cnt += 1;
        if (A[i] % 4 == 0) cnt2 += 1;
    }
    if (cnt2 >= cnt) cout << "Yes" <<endl;
    else if (n == cnt + cnt2 && cnt2 == cnt - 1) cout << "Yes" << endl;
    else cout << "No" <<endl;
    return 0;
}