#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> stu(n);
    vector<pair<int, int>> vec(m);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        stu[i] = make_pair(a, b);
    }
    rep(i, m) {
        int c, d;
        cin >> c >> d;
        vec[i] = make_pair(c, d);
    }


    for (int i=0; i<n; i++){
        int mini = abs(stu[i].first - vec[0].first) + abs(stu[i].second - vec[0].second);
        int index=1;
        for(int j=0; j<m; j++){
            int num = abs(stu[i].first - vec[j].first) + abs(stu[i].second - vec[j].second);
            if(mini > num) {
                index = j+1;
                mini = num;
            }
        }
        cout << index << endl;
    }
}