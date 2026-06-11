#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define bg begin()
#define en end()

using namespace std;

typedef long long ll;

static const ll MOD = 1000000007;

/*

caa cbb
cbb caa

ccbb ccaa ccaa
aacc aacc aabb


bba
cca

ba bc
ba bc

*/


ll ans;
int N;
char S1[55], S2[55];

int main(void) {
    scanf("%d", &N);
    scanf("%s %s", S1, S2);

    int i;
    if (S1[0] == S2[0]) {ans = 3; i = 1;}
    else { ans = 6; i = 2;}

     while (i < N) {
         ll c;
        if (S1[i] != S2[i]) {
            if (S1[i-1] != S2[i-1]) c = 3;
            else c = 2;
            
            ans *= c;
            ans %= MOD;
            i += 2;
        } else {
            if (S1[i-1] == S2[i-1]) {
                ans *= 2;
                ans %= MOD;
            }
            i++;
        }
    }
   

  
    printf("%lld\n", ans);

	return 0;
}
