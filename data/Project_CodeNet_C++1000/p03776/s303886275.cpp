#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<iomanip>
#include<stack>
#include<map>
#include<queue>
#include<set>
#define int long long
using namespace std;
const int INF = 1e10;
const int ZERO = 0;

int comb(int n, int r) {
    if(r > n) {
        return 0;
    }
    if(r * 2 > n) {
        r = n - r;
    }
    if(r == 0) {
        return 1;
    }

    int result = n;
    for(int i = 2;i <= r;i++) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

signed main() {
    int N,A,B;
    cin >> N >> A >> B;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    double ret1 = 0;
    for(int i = 0;i < A;i++) {
        ret1 += vec.at(i);
    }
  	cout << fixed;
    cout << ret1 / A << endl;
    if(vec.at(0) != vec.at(A - 1)) {
        int x = 0;
        int y = 0;
        for(int i = 0;i < A;i++) {
            if(vec.at(A - 1) == vec.at(i)) {
                x++;
                y++;
            }
        }
        for(int i = A;i < N;i++) {
            if(vec.at(A - 1) == vec.at(i)) {
                y++;
            }
        }
        cout << comb(y,x) << endl;
    }
    else {
        int x = 0;
        for(int i = 0;i < N;i++) {
            if(vec.at(0) == vec.at(i)) {
                x++;
            }
        }
        int ret2 = 0;
        for(int i = A;i <= B;i++) {
            ret2 += comb(x,i);
        }
        cout << ret2 << endl;
    }
}