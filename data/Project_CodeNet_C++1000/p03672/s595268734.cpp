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

    string S;
    io.read(S);
    int ans = -1;
    S.pop_back();
    while(!S.empty()){
        if(S.size() % 2 == 0){
            bool f = true;
            for(int i = 0; i < S.size() / 2; i++){
                if(S[i] != S[i + S.size() / 2]) f = false;
            }
            if(f){
                ans = S.size();
                break;
            }
        }
        S.pop_back();
    }
    cout << ans;
    return 0;
}