//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 5005
#define MOD 1000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int power(int x, int n) {
    if (n == 0) return 1;
    if (n&1) return (1LL*x*power(x, n-1))%MOD;
    int p = power(x, n/2);
    return (1LL*p*p)%MOD;
}

void add(int &a, int b) {a = (a+b)%MOD;}

int n, k, dp[maxN][maxN];
string s;

int main () {
    scanf("%d", &n);
    cin >> s; k = s.length();

    dp[0][0] = 1;
    fto(i, 0, n-1) {
        fto(j, 0, n-1) {
            add(dp[i+1][j+1], dp[i][j]*2);
            add(dp[i+1][max(0, j-1)], dp[i][j]);
        }
    }

    int ans = (1LL*dp[n][k]*power(power(2, MOD-2), k))%MOD;
    printf("%d", ans);

    return 0;
}
