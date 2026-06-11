#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int n;
map<int, set<int>> m;
int d_to_1[100001], d_to_n[100001];

int count_subtree(int c,int p) {
    int s = 0;
    for(auto e: m[c]) {
        if(e != p) {
            s += count_subtree(e,c);
        }
    }
    return s + 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        m[a].insert(b);
        m[b].insert(a);
    }
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        for (auto e:m[c]) {
            if (d_to_n[e] == 0 && e != n) {
                d_to_n[e] = d_to_n[c] + 1;
                q.push(e);
            }
        }
    }
    vector<int> p;
    int c = 1;
    while (c != n) {
        p.push_back(c);
        for (auto e: m[c]) {
            if (d_to_n[e] < d_to_n[c]) {
                c = e;
                break;
            }
        }
    }
    p.push_back(n);
    int r_f = p[(p.size() - p.size() / 2) - 1], r_s = p[p.size() - p.size() / 2];
    if(count_subtree(r_f,r_s) <= count_subtree(r_s,r_f)) cout << "Snuke";
    else cout << "Fennec";
    cout << endl;
}