#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    vector<int> plus(N);
    for (int i = 0; i < N; i++) {
        plus[p[i] - 1] = i+1;
    }
    vector<int> a(N), b(N);
    a[0] = plus[0];
    b[N-1] = plus[N-1];
    for (int i = 1; i < N; i++) {
        a[i] = a[i-1] + plus[i];
    }
    for (int i = N-2; i >= 0; i--) {
        b[i] = b[i+1] + plus[i];
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        printf("%d ", b[i]);
    }
    cout << endl;


}