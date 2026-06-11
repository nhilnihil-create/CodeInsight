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
#define INF 1000000000
#define eps 1e-7
#define mod 1000000007
#define int ll
using namespace std;

int N, L, T;

int next(int a) {
    if (a == N-1) return 0;
    else return a+1;
}

int prev(int a) {
    if (a == 0) return N-1;
    else return a-1;
}

int dist(int a, int b) { //座標aから座標bへ時計回りにみた距離
    if (a <= b) return b-a;
    else return L-(a-b);
}

int meet_time(int dist) {
    if (T < dist/2.) return 0;
    else {
        int cnt=1;
        double first_meet = dist/2.;
        double remain = T - first_meet;
        cnt += floor(remain / (L/2.));
        return cnt;
    }
}

int X[100000 + 10];
int W[100000 + 10];

signed main() {
    vi last_pos;
    cin >> N >> L >> T;
    rep(i, N) {
        cin >> X[i] >> W[i];
        if (W[i] == 1) last_pos.pb((X[i] + T) % L);
        else last_pos.pb((X[i] + L * (int)1e10 - T) % L);
    }
    int last;
    if (W[0] == 1) { //時計回り
        int encount=0;
        Rep(i, 1, N) {
            if (W[i] == 2) {
                encount += meet_time(dist(X[0], X[i]));
                // cout << "encount:" << encount << endl;
            }
        }
        // cout << encount << endl;
        last = encount % N;
        // cout << last << endl;
    } else { //反時計回り
        int encount=0;
        Rep(i, 1, N) {
            if (W[i] == 1) {
                encount += meet_time(dist(X[i], X[0]));
                // cout << encount << endl;
            }
        }
        // cout << encount << endl;
        last = ((N * (int)1e10) - encount) % N;
        // cout << last << endl;
    }
    
    int final_idx = last;
    // cout << "final_idx:" << final_idx << endl;
    int final_pos = last_pos[0];
    // cout << "final_pos:" << final_pos << endl;
    sort(all(last_pos));
    int new_pos;
    if (W[0] == 1) { //時計回り
        rev(i, N) {
            if (last_pos[i] == final_pos) {
                new_pos = i;
                break;
            }
        }
    } else {
        rep(i, N) {
            if (last_pos[i] == final_pos) {
                new_pos = i;
                break;
            }
        }
    }
    // cout << "new_pos:" << new_pos << endl;
    int k = (new_pos + (N * (int)1e10) - final_idx) % N;
    rep(i, N) {
        cout << last_pos[k] << endl;
        k = next(k);
    }
    
    return 0;
}