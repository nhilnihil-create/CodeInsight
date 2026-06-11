#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    --N;
    A = max(A, B) - min(A, B);
    B = C + D;
    puts(A <= D * N && (A + B - C * N % B) % B <= N * (D - C) ? "YES" : "NO");
    return 0;
}