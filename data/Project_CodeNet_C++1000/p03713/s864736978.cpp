#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<numeric>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

using ll = long long;

class Stream{
public:
    Stream(){

    }
    //配列以外の入力を受け取る
    void read(){

    }
    template<typename First, typename... Rest>
    void read(First& first, Rest&... rest){
        cin >> first;
        read(rest...);
    }
    template<typename T>
    vector<T> read_vec(size_t n){
        vector<T> tmp(n);
        for(size_t i = 0; i < n; i++){
            cin >> tmp[i];
        }
        return tmp;
    }
    //配列を区切って出力する
    template<typename T>
    void write_vec(vector<T>& v, char divider){
        for(size_t i = 0; i < v.size(); i++){
            cout << v[i] << divider;
        }
    }
};

int main(){
    Stream io;

    ll H, W;
    io.read(H, W);
    ll ans;
    if(H % 3 == 0 || W % 3 == 0) ans = 0;
    else ans = min(H, W);
    for(ll i = 1; i < H; i++){
        multiset<ll> S;
        S.insert(i * W);
        S.insert(W / 2 * (H - i));
        S.insert((W - W / 2) * (H - i));
        ans = min(ans, *S.rbegin() - *S.begin());
    }
    for(ll i = 1; i < W; i++){
        multiset<ll> S;
        S.insert(i * H);
        S.insert(H / 2 * (W - i));
        S.insert((H - H / 2) * (W - i));
        ans = min(ans, *S.rbegin() - *S.begin());
    }
    cout << ans;
    return 0;
}