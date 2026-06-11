#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

int H,W,d;
char grid[500][500];

void solveodd() {
    F0R(i,H) {
        F0R(j,W) {
            if (i % 2 == 0) {
                if (j % 2 == 0) grid[i][j] = 'R';
                else grid[i][j] = 'Y';
            } else {
                if (j % 2 == 0) grid[i][j] = 'G';
                else grid[i][j] = 'B';
            }
        }
    }
    F0R(i,H) {
        F0R(j,W) cout << grid[i][j];
        cout << "\n";
    }
}

void fill(int x, int y, char c) {
    vector<pii> todo;
    F0R(i,d/2) FOR(j,-(d/2-i)+1,d/2-i) todo.pb({x-i,y+j});
    F0R(i,d/2) FOR(j,-(d/2-i)+1,d/2-i) todo.pb({x+1+i,y+j});
    for (auto a: todo) if (0 <= a.f && a.f < H && 0 <= a.s && a.s < W) grid[a.f][a.s] = c;
}

void solveeven() {
    F0R(i,H) F0R(j,W) grid[i][j] ='*';
    FOR(i,-505,H+505) FOR(j,-505,W+505) {
        if (i % d == 0 && j % d == 0) {
            if ((i/d+j/d) % 2 == 0) fill(i,j,'R');
            else fill(i,j,'Y');
        } else if (((i%d)+d)%d == (d/2) && ((j%d)+d)%d == (d/2)) {
            if (((i-d/2)/d+(j-d/2)/d) % 2 == 0) fill(i,j,'G');
            else fill(i,j,'B');
        }
    }
    F0R(i,H) {
        F0R(j,W) cout << grid[i][j];
        cout << "\n";
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> H >> W >> d;
	if (d % 2 == 1) solveodd();
	else solveeven();
}

// read!
// ll vs. int!