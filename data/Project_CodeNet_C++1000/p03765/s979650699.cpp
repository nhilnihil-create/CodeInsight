#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define all(x)  x.begin(),x.end()
#define sz(x)   (int)x.size()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 2e5 + 5;

typedef pair<int,int>   ii;

int cnt1[N];
int cnt2[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string S;   cin >> S;
    string T;   cin >> T;

    for(int i = 1 ; i <= sz(S) ; ++i)   cnt1[i] = cnt1[i - 1] + (S[i - 1] == 'B');
    for(int i = 1 ; i <= sz(T) ; ++i)   cnt2[i] = cnt2[i - 1] + (T[i - 1] == 'B');

    int q;  cin >> q;

    while (q--) {
        int l1, r1; cin >> l1 >> r1;
        int l2, r2; cin >> l2 >> r2;

        int cnt1B = cnt1[r1] - cnt1[l1 - 1];
        int cnt2B = cnt2[r2] - cnt2[l2 - 1];

        int cnt1A = r1 - l1 + 1 - cnt1B;
        int cnt2A = r2 - l2 + 1 - cnt2B;

        int R1 = (cnt1A - cnt1B + 1000002) % 3;
        int R2 = (cnt2A - cnt2B + 1000002) % 3;

        if (R1 == R2)   cout << "YES\n";
        else            cout << "NO\n";
    }
}
