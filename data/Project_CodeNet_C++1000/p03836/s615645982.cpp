#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
//using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dh[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dw[8] = {1, -1, 0, 1, -1, 0, 1, -1};
  
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * (B / gcd(A, B));
}
using Graph = vector<vector<int>>;
Graph G;
  
/*------------------------------------------------------------------*/
string str(int m, char s){
    string re = "";
    rep(i, m) re += s;
    return re;
}

int main(){
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    vector<char> c{'U', 'D', 'L', 'R'};
    int dx = tx - sx;
    int dy = ty - sy;
    
    cout << str(dy, c[0]) << str(dx, c[3]) << str(dy, c[1]) << str(dx, c[2]) 
         << str(1, c[2]) << str(dy + 1, c[0]) << str(dx + 1, c[3]) << str(1, c[1])
         << str(1, c[3]) << str(dy + 1, c[1]) << str(dx + 1, c[2]) << str(1, c[0])
         << endl; 
}