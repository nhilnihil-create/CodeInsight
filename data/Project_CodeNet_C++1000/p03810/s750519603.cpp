#include <bits/stdc++.h>
#define pb push_back
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int N=110000;
int n, x[N];

int gcd(int x, int y) {
    while(y) {
        int t=y;
        y=x%t;
        x=t;
    }
    return x;
}

int win() {
    int i, t, io, ne;
    for(t=x[0], i=1; i<n; i++) t=gcd(t, x[i]);
    for(i=0; i<n; i++) x[i]/=t;
    for(io=-1, ne=i=0; i<n; i++) {
        if(x[i]%2==0) ne++;
        else if(x[i]>1) io=i;
    }
    if(ne%2) return 1;
    if(ne<n-1 || io==-1) return 0;
    x[io]--;
    return !win();
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &x[i]);
    printf(win()? "First\n" : "Second\n");
    return 0;
}