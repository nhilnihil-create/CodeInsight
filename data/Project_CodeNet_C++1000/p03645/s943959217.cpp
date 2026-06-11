#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

vector<vector<int>> m;

bool possible(int s,int pre,int count){
    bool ans = false;
    if(count == 2){
        if(s == 1) return true;
        else return false;
    } 
    for(auto num : m[s]){
        if(num != pre) ans |= possible(num,s,count+1); 
    }
    return ans;
}

int main(){
    int N,M;
    cin >> N >> M;
    m.resize(N+1);
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        m[a].emplace_back(b);
        m[b].emplace_back(a);
    }
    if(possible(N,-1,0)) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}
