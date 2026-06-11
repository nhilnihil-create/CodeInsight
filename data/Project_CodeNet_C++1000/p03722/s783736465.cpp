#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<int, ll> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<p> > x(N);

    for(int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        x[a].push_back(make_pair(b, c));
    }

    vector<vector<bool> > b(N, vector<bool>(N));

    stack<p> s;

    for(int i = 0; i < N; i++) {

        for(int j = 0; j < x[i].size(); j++) {
            s.push(make_pair(x[i][j].first, x[i][j].second));
        }

        while(!s.empty()) {
            int pos = s.top().first;
            ll l = s.top().second;
            s.pop();

            if(pos == i) {
                if(l > 0) b[i][i] = true;
                continue;
            }

            if(b[i][pos]) continue;
            b[i][pos] = true;

            for(int j = 0; j < x[pos].size(); j++) {
                s.push(make_pair(x[pos][j].first, l + x[pos][j].second));
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(b[0][i] && b[i][i] && b[i][N - 1]) {
            cout << "inf" << endl;
            return 0;
        }
    }

    vector<ll> c(N, -pow(10, 18));

    queue<int> q;

    int count = 0;

    q.push(0);

    c[0] = 0;

    while(!q.empty()) {
        count++;
        if(count > 2000100) {
            break;
        }

        int pos = q.front();
        q.pop();

        ll l = c[pos];

        for(int i = 0; i < x[pos].size(); i++) {
            if(l + x[pos][i].second > c[x[pos][i].first]) {
                c[x[pos][i].first] = l + x[pos][i].second;
                q.push(x[pos][i].first);
            }
        }
    }

    cout << c[N - 1] << endl;
}