#include <bits/stdc++.h>

#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int N = 2e5 + 10;

char s[N], t[N];
int sumS[N], sumT[N], q;

int main(){
    if (fopen("inp.txt", "r")){
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> (s + 1) >> (t + 1);

    FOR(i, 1, strlen(s + 1))
        sumS[i] = sumS[i - 1] + (s[i] == 'A'? 1 : 2);
    FOR(i, 1, strlen(t + 1))
        sumT[i] = sumT[i - 1] + (t[i] == 'A'? 1 : 2);

    cin >> q;
    while (q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (abs((sumS[b] - sumS[a - 1]) - (sumT[d] - sumT[c - 1])) % 3 == 0? "YES" : "NO") << endl;
    }

    return 0;
}
