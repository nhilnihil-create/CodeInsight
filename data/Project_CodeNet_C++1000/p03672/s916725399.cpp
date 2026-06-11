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
    string s;
    cin >> s;

    int l = (int)s.size();
    while(l != 0){
        s.pop_back();
        s.pop_back();
        l = (int)s.size();
        string front = s.substr(0,l/2);
        string back = s.substr(l/2,l/2);
        if(front==back){
            cout(l);
            break;
        }
    }
    return 0;
}