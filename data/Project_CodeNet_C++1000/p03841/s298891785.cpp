#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> Pii;

const int N_MAX = 500;

vector<Pii> v(N_MAX+1, Pii(0, 0));
 
bool check(int n) {
    // それぞれ [1, i], [i, n] に含まれるべきことが確定している要素の数
    vector<int> cnt_l(n*n+1, 0), cnt_r(n*n+2, 0);
    for(int i=1;i<=n;++i) {
        cnt_l[v[i].first] += i;
        cnt_r[v[i].first] += n-i+1;
    }
    for(int i=1;i<=n*n;++i) cnt_l[i] += cnt_l[i-1];
    for(int i=n*n;i>=1;--i) cnt_r[i] += cnt_r[i+1];

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

    // x_i にしたがって数値を入れる
    for(int j=1;j<=n;++j) {
        int idx = v[j].first;
        int num = v[j].second;
        ret[idx] = num;
    }

    // x_i で指定されたインデックスより前の部分を埋める
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
    
    // x_i で指定されたインデックスより後の部分を埋める
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

    return ret;
}

int main() {
    int n, x;
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> x;
        v[i] = {x, i};
    }

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
