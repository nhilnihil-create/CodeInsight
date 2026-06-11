#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N;
vector<int> x;

using pint = pair<int,int>;
vector<int> po; // その場所に制約があるなら、そこに置かれる数、なければ 0
vector<int> con; // con[i] := i 番目の checkpoint についての数

int main() {
    int N; cin >> N;
    x.resize(N); for (int i = 0; i < N; ++i) cin >> x[i], --x[i];
    po.resize(N*N, 0);
    for (int i = 0; i < N; ++i) po[x[i]] = i + 1;
    con.clear();
    for (int i = 0; i < N*N; ++i) if (po[i]) con.push_back(po[i]);
    
    int iter = 0;
    vector<int> num(N+2, 0); // num[i] := 数 i を何個使ったか
    vector<int> res(N*N, 0);
    set<int> alr;
    bool ok = true;
    for (int i = 0; i < N*N; ++i) {
        if (!ok) break;
        if (po[i]) {
            if (num[po[i]] < po[i]-1) { ok = false; break; }
            res[i] = po[i];
            ++num[po[i]];
            alr.insert(po[i]);
        }
        else {
            while (iter < N && num[con[iter]] >= con[iter]-1) ++iter;
            if (iter == N) {
                int canuse = 1;
                while (canuse <= N && (!alr.count(canuse) || num[canuse] == N)) ++canuse;
                if (canuse == N + 1) { ok = false; break; }
                res[i] = canuse;
                ++num[canuse];
            }
            else {
                res[i] = con[iter];
                ++num[con[iter]];
            }
        }
    }
    
    if (!ok) puts("No");
    else {
        puts("Yes");
        for (int i = 0; i < N*N; ++i) cout << res[i] << " ";
        cout << endl;
    }
}