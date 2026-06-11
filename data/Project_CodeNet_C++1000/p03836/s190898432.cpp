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
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int x, y; x = tx - sx; y = ty - sy;
    for (int i = 0; i < y; i++) {
        printf("U");
    }
    for (int i = 0; i < x; i++) {
        printf("R");
    }
    for (int i = 0; i < y; i++) {
        printf("D");
    }
    for (int i = 0; i < x+1; i++) {
        printf("L");
    }
    for (int i = 0; i < y+1; i++) {
        printf("U");
    }
    for (int i = 0; i < x+1; i++) {
        printf("R");
    }
    printf("D");
    printf("R");
    for (int i = 0; i < y+1; i++) {
        printf("D");
    }
    for (int i = 0; i < x+1; i++) {
        printf("L");
    }
    printf("U\n");

}