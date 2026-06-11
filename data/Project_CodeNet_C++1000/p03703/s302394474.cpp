#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

int sqrtN = 512;
struct SqrtDecomposition{
    int N, K;
    vector <long long> data;
    vector <long long> bucketSum;

    SqrtDecomposition(int n){
        N = n;
        K = (N + sqrtN - 1) / sqrtN;
        data.assign(N, 0);
        bucketSum.assign(K, 0);
    }

    void add(int x, int y){
        data[x] += y;
        bucketSum[x / sqrtN] += y;
    }

    long long getSum(int x, int y){
        long long ans = 0;
        if(y - x < sqrtN){
            for(int i = x; i < y; i++){
                ans += data[i];
            }
            return ans;
        }
        for(int i = x / sqrtN + 1; i < y / sqrtN; i++){
            ans += bucketSum[i];
        }

        for(int i = x; i < (x / sqrtN + 1) * sqrtN; i++){
            ans += data[i];
        }
        for(int i = y / sqrtN * sqrtN; i < y; i++){
            ans += data[i];
        }
        return ans;
    }

};

long long a[200000];
pair <long long, int> sum_to_ind[200000];
int main(){
    int N;
    long long K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
      cin >> a[i];
    }

    sum_to_ind[0] = make_pair(a[0] - K, 0);
    for(int i = 1; i < N; i++){
      sum_to_ind[i] = make_pair(a[i] - K + sum_to_ind[i - 1].first, i);
    }

    sort(sum_to_ind, sum_to_ind + N);

    long long ans = 0;
    SqrtDecomposition sq(N);
    for(int i = N - 1; i >= 0; i--){
      int cur_ind = sum_to_ind[i].second;
      int bigger_inds = sq.getSum(0, cur_ind);
      if(sum_to_ind[i].first >= 0){
        ans += (cur_ind + 1 - bigger_inds);
      } else {
        ans += (cur_ind - bigger_inds);
      }
      sq.add(cur_ind, 1);
    }
    cout << ans << endl;
    return 0;
}
