#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct BIT{
    int size;
    vector<long long> bit;
    void init(int n){
        size = n;
        bit.assign(size+1, 0);
    }

    // from 1 to x (inclusive)
    long long sum(int x){
        long long res = 0;
        while(x > 0){
            res += bit[x];
            x -= (x & -x);
        }
        return res;
    }

    void add(int x, long long y){
        while(x <= size){
            bit[x] += y;
            x += (x & -x);
        }
    }
};

long long inv_num(int n, vector<long long> array){
    long long res = 0;
    vector<long long> v;
    BIT b;
    b.init(n);
    v.assign(array.begin(), array.end());
    sort(v.begin(), v.end());
    auto tmp = unique(v.begin(), v.end());
    v.erase(tmp, v.end());
    for(int i=0;i<n;i++){
        int val = (int)(lower_bound(v.begin(), v.end(), array[i]) - v.begin()) + 1;
        res += i - b.sum(val);
        b.add(val, 1);
    }
    return res;
}

int main(void){
    int n, k;
    vector<long long> v;
    cin >> n >> k;
    v.push_back(0);
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        v.push_back(v.back() + a - k);
    }

    cout << (long long)n * (n+1) / 2 - inv_num(n+1, v) << endl;
}
