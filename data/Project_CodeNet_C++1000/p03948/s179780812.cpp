#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vv vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int> >
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define INF 100000000000
#define eps 1e-7
#define mod 1000000007
#define int ll
using namespace std;

int A[100000 + 10];
int M[100000 + 10]; //i番目の店でリンゴ買った時に売れる最高額

signed main(void) {
    int N, T;
    cin >> N >> T;
    rep(i, N) {
        cin >> A[i];
    }
    int Max = A[N-1];
    M[N-1] = 0;
    for (int i=N-2; i>=0; i--) {
        M[i] = Max;
        if (A[i] > Max) Max = A[i];
    }

    int Mmargin = 0;
    rep(i, N) {
        Mmargin = max(Mmargin, M[i]-A[i]);
    }

    int n_chance=0;
    rep(i, N) {
        if (M[i]-A[i] == Mmargin) n_chance++;
    }

    cout << n_chance << endl;
    return 0;
}