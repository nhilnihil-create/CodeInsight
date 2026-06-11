#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
int n, m, q;
int a[51], b[51], c[51], d[51];
int v[11];
 
int main() {
    int N;
    cin >> N;
    int* nums = new int[N];
    rep(i, 0, N){
        cin >> nums[i];
    }
    long long min = 2000001;
    rep(i, -100, 101){
        long long cost = 0;
        rep(j, 0, N){
            cost += (nums[j] - i) * (nums[j] - i);
        }
        if (min > cost){
            min = cost;
        }
    }
    cout << min << endl;
    return 0;
}
