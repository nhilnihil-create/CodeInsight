#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int N = 1e5 + 100;
int n, a[N];

int gcd(int a, int b) { return a ? gcd(b%a,a) : b; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int sum = 0;
    cin >> n;
    forn(i,n) {
        cin >> a[i];
        sum += a[i]&1;
    }

    bool first = false;
    if (n%2 != sum%2) first = true;
    else if (n%2 == 1) {
        int turns = 0;
        while (true) {
            int pick = -1;
            forn(i,n) if (a[i]%2 == 1 && a[i] > 1) {
                pick = i;
                break;
            }

            if (pick == -1) break;
            a[pick]--;
            int g = 0; forn(i,n) g = gcd(g,a[i]);
            sum = 0; forn(i,n) a[i] /= g, sum += a[i]&1; 

            if (sum%2 == 1) turns++;
            else break;
        }
        first = turns%2 == 1;
    }
    cout << (first ? "First" : "Second") << endl;

    return 0;
}
