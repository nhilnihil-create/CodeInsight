#include <bits/stdc++.h>
using namespace std;
long long Com(long long a, long long b){
    long long L = 1;
    long long c = max(a-b,b);
    long long d = min(a-b,b);
    for(long long i = c+1; i <= a; i++) L *= i;
    for(long long i = 2; i <= d; i++) L /= i;
    return L;
}

int main(void){
    long long N,P;
    cin >> N >> P;
    vector<long long> A(N),O,E;
    for(long long i = 0; i < N; i++){
        cin >> A[i];
        if(A[i]%2 == 1) O.push_back(A[i]);
        else E.push_back(A[i]);
    }
    long long o = O.size(),e = E.size(),ans = 0;
    long long F = 1;
    for(long long i = 0; i < e; i++) F *= 2;
    if(P == 1){
        long long i = 1;
        while(i <= o){
            long long C = Com(o,i);
            ans += C * F;
            i += 2;
        }
        cout << ans << endl;
    }
    if(P == 0){
        long long i = 2;
        ans += F;
        while(i <= o){
            long long C = Com(o,i);
            ans += C * F;
            i += 2;
        }
        cout << ans << endl;
    }
}