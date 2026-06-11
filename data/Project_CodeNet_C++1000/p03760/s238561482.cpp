#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5 + 10;


int main(){
    string o,e;
    cin >> o >> e;

    int l = (int)o.size() + (int)e.size();
    string s;
    for(int i=0; i<l; ++i){
        if(i%2==0) s += o[i/2];
        else s += e[i/2]; 
    }
    cout(s);
    return 0;
}