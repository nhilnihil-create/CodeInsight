#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,pii> iii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef priority_queue<pii, vector<pii>, greater<pii>> fila_prioridade;
typedef priority_queue<iii, vector<iii>, greater<iii>> fila_prioridade_grids;

#define nl '\n'
#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int oversea = 0, qtd_passados = 0;
int a,b,n;
string s;

int main() {
        NeedForSpeed

        cin >> n >> a >> b;

        cin >> s;

        for (int i = 0; i < n; i++) {
                if (s[i] == 'a') {
                        if (qtd_passados < a + b) {
                                cout << "Yes" << nl;
                                qtd_passados++;
                        } else {
                                cout << "No" << nl;
                        }
                } else if (s[i] == 'b') {
                        if (qtd_passados < a + b && oversea < b) {
                                cout << "Yes" << nl;
                                oversea++;
                                qtd_passados++;
                        } else {
                                cout << "No" << nl;
                        }
                } else {
                        cout << "No" << nl;
                }
        }

        return 0;
}
