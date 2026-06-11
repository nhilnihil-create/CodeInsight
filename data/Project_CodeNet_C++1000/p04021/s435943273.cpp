#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)

int main(){
    int N; cin >> N;
    vector<int> A(N), B(N);
    REP(i,N) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(all(A));
    int cnt = 0;
    REP(i,N) {
        int n1 = lower_bound(all(A),B[i])-A.begin();
        if ((n1+i)%2) cnt++;
    }
    cout << cnt/2 << endl;
    return 0;
}