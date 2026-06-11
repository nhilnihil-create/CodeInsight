#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define F first
#define S second
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define VanLoi "a"
#define gb(i, j) ((i >> j) & 1)
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int, int>
#define Block 400

using namespace std;

int n, t1[maxn], t2[maxn];
string S, T;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(VanLoi".inp", "r", stdin);
    //freopen(VanLoi".out", "w", stdout);
    cin >> S;
    cin >> T;
    fi(i, 1, S.length()) {
        if (S[i - 1] == 'A') t1[i] = t1[i - 1] + 2;
            else t1[i] = t1[i - 1] + 1;
    }
    fi(i, 1, T.length()) {
        if (T[i - 1] == 'A') t2[i] = t2[i - 1] + 2;
            else t2[i] = t2[i - 1] + 1;
    }
    cin >> n;
    fi(z, 1, n) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        int tg = t1[x2] - t1[x1 - 1], tg1 = t2[y2] - t2[y1 - 1];
        if (tg % 3 == tg1 % 3) cout << "YES" << '\n';
            else cout << "NO" << '\n';
    }
    return 0;
}
