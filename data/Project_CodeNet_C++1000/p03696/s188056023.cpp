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
using Edge = pair<int,int>;
using Graph = vector<vector<Edge>>;
Graph G;
  
/*------------------------------------------------------------------*/

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int l_count = 0, r_count = 0;
    rep(i, n){
        if(s[i] == '(') l_count++;
        else if(s[i] == ')'){
            if(l_count == 0) r_count++;
            else if(l_count > 0) l_count--;
        }
    }
    //cout << l_count << " " << r_count << endl;
    rep(i, l_count) s += ')';
    rep(i, r_count) s = '(' + s;
    cout << s << endl;
}