#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

int main(){
    int x, ans = 0;
    scanf("%d", &x);
    for(ans=1;;ans++){
        x -= ans;
        if(x <= 0) break;
    }
    printf("%d\n", ans);
}