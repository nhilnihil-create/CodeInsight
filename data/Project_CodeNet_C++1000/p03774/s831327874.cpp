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

    int N, M;
    io.read(N, M);
    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(M);
    vector<int> d(M);
    for(int i = 0; i < N; i++){
        io.read(a[i], b[i]);
    }
    for(int i = 0; i < M; i++){
        io.read(c[i], d[i]);
    }
    for(int i = 0; i < N; i++){
        int dist = abs(a[i] - c[0]) + abs(b[i] - d[0]);
        int p = 0;
        for(int j = 1; j < M; j++){
            int ndist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if(ndist < dist){
                dist = ndist;
                p = j;
            }
        }
        cout << p + 1 << '\n';
    }
    return 0;
}