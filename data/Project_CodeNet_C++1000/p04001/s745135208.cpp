#include <bits/stdc++.h>
using namespace std;

long int all_sum(long int S, long int keta, long int sum){
    if(S / keta == 0) return S + sum;

    long int wakeru, wakenai;
    wakeru  = all_sum(S / keta, 10       , sum + (S % keta));
    wakenai = all_sum(S       , keta * 10, sum             );

    return wakeru + wakenai;
}

int main() {
    long int S;
    cin >> S;

    long int answer;

    answer = all_sum(S, 10, 0);

    cout << answer << endl;
}
