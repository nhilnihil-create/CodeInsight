#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
ll Q, H, S, D;
cin >> Q >> H >> S >> D;
ll N;
cin >> N;
Q *= 4;
H *= 2;
ll ans;
ll one = min({Q, H, S});
if(N % 2 == 0){
one *= 2;
ll two = min(one, D);
ans = two*(N/2);
}
else{
    int kari = one;
one *= 2;
ll two = min(one, D);
ans = two*(N/2);
ans += kari;
}

cout << ans << endl;
}