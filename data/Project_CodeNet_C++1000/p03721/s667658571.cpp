#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
//stoi(s) : string→int stoll(s) :string→longlong  int→string to_string(i)
const double PI = acos(-1.0);
//小数点の表し方 cout << fixed << setprecision(5);

int main(){
    int n;
    ll k;
    cin >> n >> k;
    map<int,ll> m;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        m[a] += b;
    }
    ll cnt = 0;
    for(auto x:m){
        cnt += x.second;
        if(cnt >= k){
            cout << x.first << endl;
            return 0;
        }
    }
}