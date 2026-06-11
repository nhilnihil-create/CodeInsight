#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
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
    
    int a, b, c;
    io.read(a, b, c);
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(a);
    q.push(b);
    q.push(c);
    int ans = 0;
    ans += q.top();
    q.pop();
    ans += q.top();
    q.pop();
    cout << ans;
    return 0;
}