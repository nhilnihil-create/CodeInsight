#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

using ll = long long;

void read();
template<typename First, typename... Rest> void read(First& first, Rest&... rest);
void write();
template<typename First, typename... Rest> void write(First first, Rest... rest);
template<typename T> void write_vec(vector<T>& v, char divider);

int main(){
    string S;
    read(S);
    string ans = "YES";
    int i = S.size() - 1;
    while(i >= 0){
        string s5 = (i - 4 >= 0)? S.substr(i - 4, 5) : "";
        string s6 = (i - 5 >= 0)? S.substr(i - 5, 6) : "";
        string s7 = (i - 6 >= 0)? S.substr(i - 6, 7) : "";
        if(s5 == "dream" || s5 == "erase"){
            i -= 5;
        }
        else if(s6 == "eraser"){
            i -= 6;
        }
        else if(s7 == "dreamer"){
            i -= 7;
        }
        else {
            ans = "NO";
            break;
        }
    }
    write(ans);
    return 0;
}

//配列以外の入力を受け取る
void read(){

}
template<typename First, typename... Rest>
void read(First& first, Rest&... rest){
    cin >> first;
    read(rest...);
}
//
//配列以外を出力する
void write(){

}
template<typename First, typename... Rest>
void write(First first, Rest... rest){
    cout << first << " ";
    write(rest...);
}
//
//配列を区切って出力する
template<typename T>
void write_vec(vector<T>& v, char divider){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << divider;
    }
}
//