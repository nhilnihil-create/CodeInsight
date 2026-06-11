/// Source : https://atcoder.jp/contests/arc060/tasks/arc060_c
/// Author : liuyubobobo
/// Time   : 2020-09-24

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


/// Binary Lifting
/// Time Complexity: init: O(nlogn + nlog|max_dis|)
///                  query: O(log|max_dis| * logn)
/// Space Complexity: O(nlog|max_dis|)
class Hotels{

private:
    vector<vector<int>> dp;

public:
    Hotels(int N, int L, vector<int>& hotels) : dp(N){

        for(int i = 0; i < N; i ++){
            vector<int>::iterator iter = lower_bound(hotels.begin(), hotels.end(), hotels[i] + L);
            if(iter == hotels.end() || *iter > hotels[i] + L)
                iter --;
            dp[i].push_back(iter - hotels.begin());
        }
//        cout << "k == 0 completed" << endl;

        for(int k = 1; dp[0].back() != N - 1; k ++){
            for(int i = 0; i < N; i ++)
                dp[i].push_back(dp[dp[i][k - 1]][k - 1]);
        }
//        cout << "init completed" << endl;
    }

    int query(int a, int b){

        a --, b --;
        if(a > b) swap(a, b);

        int cur = a, res = 0;
        while(cur < b){
            int k = lower_bound(dp[cur].begin(), dp[cur].end(), b) - dp[cur].begin();
            if(k == 0) return res + 1;
            res += (1 << (k - 1));
            cur = dp[cur][k - 1];
        }
        return res;
    }

private:
    int binary_search(const vector<int>& v, int target){

        int l = -1, r = v.size() - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(v[mid] > target) r = mid - 1;
            else l = mid;
        }
        return l;
    }
};

int main() {

//    vector<int> hotels1 = {1, 3, 6, 13, 15, 18, 19, 29, 31};
//    Hotels h1(9, 10, hotels1);
//    cout << h1.query(1, 8) << endl; // 4
//    cout << h1.query(7, 3) << endl; // 2
//    cout << h1.query(6, 7) << endl; // 1
//    cout << h1.query(8, 5) << endl; // 2
//    cout << h1.query(1, 9) << endl; // 5
//
//    for(int a = 1; a < 9; a ++)
//        for(int b = a + 1; b <= 9; b ++)
//            cout << a << " " << b << " : " << h1.query(a, b) << endl;
//    cout << "test completed!" << endl;

    int N;
    scanf("%d", &N);

    vector<int> hotels(N);
    for(int i = 0; i < N; i ++) scanf("%d", &hotels[i]);

    int L;
    scanf("%d", &L);

    Hotels h(N, L, hotels);

    int Q, a, b;
    scanf("%d", &Q);
    while(Q --){
        scanf("%d%d", &a, &b);
        printf("%d\n", h.query(a, b));
    }

    return 0;
}
