#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(i64 i = 0; i < N; i++)
#define Rep(i, k, N) for(i64 i = k; i < N; i++)
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define Cout(s) cout << s << endl
string Yes(bool b) {if(b){return "Yes";} else {return "No";}}
string YES(bool b) {if(b){return "YES";} else {return "NO";}}

int main(){
    i64 N;
    cin >> N;
    vector<i64> A(N+1, 0), sum(N+1, 0);
    rep(i, N) cin >> A[i];

    sort(all(A));
    Rep(i, 1, N+1) sum[i] = sum[i-1] + A[i];

    auto check = [&](int mid) -> bool {
        while(mid <= N && A[mid+1] <= 2*sum[mid]) mid++;
        return mid == N+1;
    };

    int ok = N+1, ng = 0;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;

        if(check(mid) == 1) ok = mid;
        else ng = mid; 
    } 

    cout << N - ng << endl;
}
