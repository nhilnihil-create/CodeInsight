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

    int H, W;
    io.read(H, W);
    auto C = io.read_vec<string>(H);
    vector<string> ans(2 * H);
    for(int i = 0; i < 2 * H; i++){
        for(int j = 0; j < W; j++){
            ans[i].push_back(C[i / 2][j]);
        }
    }
    for(int i = 0; i < 2 * H; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}