#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 100010;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
using Graph = vector<vector<int>>;
Graph G;
/*------------------------------------------------------------------*/
int main(){
    string s; cin >> s;

    int count_t = 0, count_s = 0;

    rep(i, s.size()){
        if(s[i] == 'T'){
            if(count_s == 0) count_t++;
            else count_s--;
        }else count_s++;
    }
    cout << count_t + count_s << endl;
}