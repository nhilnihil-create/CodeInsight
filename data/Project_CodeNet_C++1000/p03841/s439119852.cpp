#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> Pii;

const int N_MAX = 500;

 
vector<int> cnt_l(N_MAX*N_MAX+1, 0), cnt_r(N_MAX*N_MAX+2, 0);
vector<Pii> v(N_MAX+1, Pii(0, 0));
 
bool check(int n) {
    for(int i=1;i<=n*n;++i) {
        if(i < cnt_l[i] || n*n-i+1 < cnt_r[i]) {
            return false;
        }
    }
    return true;
}

vector<int> construct(int n) {
    vector<int> ret(n*n+1, 0);
    sort(v.begin(), v.begin()+n+1);
    int i = 1;
    for(int j=1;j<=n;++j) {
        int idx = v[j].first;
        int num = v[j].second;
        ret[idx] = num;
    }
    for(int k=1;k<=n*n;++k) {
        cerr << ret[k] << " ";
    }
    cerr << endl;

    int j = 1;
    int num = v[j].second;
    int num_cnt = num - 1;
    for(int i=1;i<=n*n;++i) {
        if(ret[i]) continue;
        while(j < n && !num_cnt) {
            ++j;
            num = v[j].second;
            num_cnt = num - 1;
        }
        if(j == n && !num_cnt) break;
        ret[i] = num;
        --num_cnt;
    }
    for(int k=1;k<=n*n;++k) {
        cerr << ret[k] << " ";
    }
    cerr << endl;
    
    j = 1;
    num = v[j].second;
    num_cnt = n - num;
    for(int i=1;i<=n*n;++i) {
        if(ret[i]) continue;
        while(j < n && !num_cnt) {
            ++j;
            num = v[j].second;
            num_cnt = n - num;
        }
        if(j == n && !num_cnt) break;
        ret[i] = num;
        --num_cnt;
    }
    for(int k=1;k<=n*n;++k) {
        cerr << ret[k] << " ";
    }
    cerr << endl;
    return ret;
}

int main() {
    int n, x;
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> x;
        v[i] = {x, i};
        cnt_l[x] += i;
        cnt_r[x] += n-i+1;
    }
    for(int i=1;i<=n*n;++i) cnt_l[i] += cnt_l[i-1];
    for(int i=n*n;i>=1;--i) cnt_r[i] += cnt_r[i+1];

    if(check(n)) {
        cout << "Yes" << endl;
        vector<int> ans = construct(n);
        for(int i=1;i<=n*n;++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

}
