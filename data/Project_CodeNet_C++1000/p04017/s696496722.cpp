#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }

    vector<int> right(n);
    for(int i=0; i<n-1; i++){
        right[i] = x[i+1] - x[i];
    }
    right[n-1] = -1;
    int klim = log2(n) + 1;
    // i から 2^k 右へ行くのにかかる距離、n を超える場合は -1
    vector<vector<int>> kright(klim, vector<int>(n, -1));
    for(int i=0; i<n; i++){
        kright[0][i] = right[i];
    }
    for(int k=1; k<klim; k++){
        for(int i=0; i<n; i++){
            if(i + (1<<k) < n){
                kright[k][i] = kright[k-1][i] + kright[k-1][i+(1<<(k-1))];
            }
            else{
                kright[k][i] = -1;
            }
        }
    }

    vector<int> next_hotel(n);

    auto n_hotel = [&](int s, int l) -> int{
        // l 以下の距離にある最も右のホテル
        // int dis = 0;
        for(int k=klim-1; k>=0; k--){
            if(kright[k][s] != -1){
                if(l >= kright[k][s]){
                    // 右へ 2^k 進める
                    l -= kright[k][s];
                    s += (1<<k);
                }
            }
        }
        return s;
    };
    
    int l, q;   
    cin >> l >> q;
    
    for(int i=0; i<n-1; i++){
        next_hotel[i] = n_hotel(i, l);
    }
    next_hotel[n-1] = -1;

    // m_days_right[k][i] は i から 2^k 日右へ進んだときのホテル
    // 無駄だったときは -1, m_days_right[k][n-1] はいつも -1
    vector<vector<int>> m_days_right(klim, vector<int>(n, -1));
    for(int i=0; i<n; i++){
        m_days_right[0][i] = next_hotel[i];
    }
    for(int k=1; k<klim; k++){
        for(int i=0; i<n; i++){
            if(m_days_right[k-1][i] != -1){
                m_days_right[k][i] = m_days_right[k-1][m_days_right[k-1][i]];
            }
        }
    }

    auto min_days = [&](int a, int b, int l) -> int{
        // a <= b
        int now = a;
        int days = 0;
        // 二分探索
        for(int k=klim-1; k>=0; k--){
            if(m_days_right[k][a] != -1 && b > m_days_right[k][a]){
                a = m_days_right[k][a];
                days += (1<<k);
            }
        }
        return days + 1;
    };

    vector<int> ans(q);
    for(int qq=0; qq<q; qq++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a > b) swap(a, b);
        ans[qq] = min_days(a, b, l);
    }
    for(int i=0; i<q; i++){
        cout << ans[i] << endl;
    }
    return 0;
}