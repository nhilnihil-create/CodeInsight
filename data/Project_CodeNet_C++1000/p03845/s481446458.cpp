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

    int N;
    io.read(N);
    auto T = io.read_vec<int>(N);
    int M;
    io.read(M);
    vector<int> P(M);
    vector<int> X(M);
    for(int i = 0; i < M; i++){
        io.read(P[i], X[i]);
    }
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += T[i];
    }
    for(int i = 0; i < M; i++){
        cout << sum - (T[P[i] - 1] - X[i]) << '\n';
    }
    return 0;
}