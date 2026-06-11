#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int) n; i++)
#define repb(i, n) for (int i = (int) n; i >= 0; i--)
#define reps(i, m, n) for (int i = (int) m; i < (int) n; i++)
#define repsb(i, m, n) for (int i = (int) m; i >= (int) n; i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.begin(), v.end(),greater<int>());
#define pb(a) push_back(a)
#define ll long long int
const ll LLINF = 1e18 + 10;
int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return 1; } return 0; }
template < class T > bool chmin(T & a,const T & b) { if (b < a) { a = b; return 1; } return 0; }
//vector<vector<int>> vec(n_rows, vector<int>(n_cols, value));
using namespace std;
int main(int argc, char const * argv[]){
    string s;
    vector<bool> v(4,false);
    cin >> s;
    rep(i,s.size()){
        if(s[i]=='W')
            v[0] = true;
        else if (s[i] == 'S')
            v[1] = true;
        else if (s[i] == 'E')
            v[2] = true;
        else
            v[3] = true;
    }
    if(v[0]==v[2]&&v[1]==v[3]){
        cout<<"Yes"<<endl;
        return 0;
    }
    
    cout<<"No"<<endl;

    return 0;
}