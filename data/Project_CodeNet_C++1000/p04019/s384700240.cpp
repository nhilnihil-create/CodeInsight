#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
 
/*------------------------------------------------------------------*/
 
int main(){
    string s; cin >> s;
    vector<int> a(4, 0);
    rep(i, s.size()){
        if(s[i] == 'N')a[0]++;
        else if(s[i] == 'S')a[1]++;
        else if(s[i] == 'W')a[2]++;
        else if(s[i] == 'E')a[3]++;
    }
    if(a[0] > 0 && a[1] > 0 && a[2] > 0 && a[3] > 0){
        cout << "Yes" << endl;
    }else if(a[0] > 0 && a[1] > 0 && a[2] == 0 && a[3] == 0){
        cout << "Yes" << endl;
    }else if(a[0] == 0 && a[1] == 0 && a[2] > 0 && a[3] > 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
