#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define rev(i, n) for(int i = n;i >= 0;i--)
#define repeat(i, m, n) for(int i = m;i < n;i++)
#define repeatrev(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define itn int

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
typedef priority_queue<int> Pr;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    ll int s = 0;
    ll int g = 0;
    ll int A[N];
    ll int B[N];

    cin >> A[0];
    B[0] = A[0];
    s += A[0];
    for(int i = 1; i < N; i ++){
        cin >> A[i];
        s += A[i];
        B[i] = B[i - 1] + A[i];
    }
    ll int f = min(abs(-s +2 *  B[0]), abs(s - 2 * B[0]));

    for(int i = 1; i < N - 1; i ++){
        ll int u = abs(-s +2 *  B[i]);
        ll int q = abs(s - 2 * B[i]);
        if(f > min(u, q)) f = min(u, q);


    }
    cout << f << endl;




}