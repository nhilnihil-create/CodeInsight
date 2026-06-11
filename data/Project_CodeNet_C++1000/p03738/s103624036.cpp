#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define REP(i,a,n) for(int i = a;i < (n);i++)
#define RREP(i,a) for(int i = a;i >= 0;i--)
#define rep(i,n) for(int i = 0;i < (n);i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define range(x,min,max) ((min) <= (x) && (x) <= (max))
#define xyrange(x, minX, maxX, y, minY, maxY) (range(x, minX, maxX) && range(y, minY, maxY))

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};
const int INF = 0x3f3f3f3f;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string A, B;
    cin >> A >> B;
    string ans = "EQUAL";
    if (A.size() > B.size()) {
        ans = "GREATER";
    } else if (A.size() < B.size()) {
        ans = "LESS";
    } else {
        rep (i, A.size()) {
            if (A[0] > B[0]) {
                ans = "GREATER";
                break;
            } else if (A[0] < B[0]) {
                ans = "LESS";
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}