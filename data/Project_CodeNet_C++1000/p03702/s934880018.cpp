#include "iostream"
#include "vector"
#include "algorithm"
#include "functional"
using namespace std;

using lint = long long;

template<typename T>
T meguru_search(T ok, T ng, function<bool(T)> check){
    while(max(ok, ng) - min(ok, ng) > 1){
        T mid = (ok + ng) / 2;
        if(check(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}

int main() {
    int n;
    lint a, b;
    cin >> n >> a >> b;

    vector<lint> h(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> h[i];
    }

    auto check = [&](lint mid){
        lint cnt = 0;
        for(int i = 0 ; i < n ; ++i){
            lint t = h[i] - mid * b;
            if(t < 0){
                continue;
            }
            cnt += (t + a - b - 1) / (a - b);
        }
        return cnt <= mid;
    };
    
    lint ans = meguru_search<lint>(1LL << 30, -1, check);
    cout << ans << endl;

    return 0;
}