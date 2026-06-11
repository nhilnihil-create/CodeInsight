#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
int N;
cin >> N;
int ans = 0;
for (int i = 1;i <= N;i++) {
ans += i;
}
cout << ans << endl;
return 0;

}