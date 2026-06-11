#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep1(i,n) for(long long i=1;i<=(long long)(n);i++)
#define all(v) v.begin(),v.end()
#define Sort(v) sort(all(v))
#define Reverse(v) reverse(all(v))
#define Rsort(v) sort(all(v),greater)
#define pub(v) push_back(v)
#define pob(v) pop_back(v)
typedef long long ll;
typedef vector<ll> vel;
typedef vector<vector<ll>> vel2d;
typedef string str;
typedef pair<ll,ll> pal;
typedef vector<str> ves;
typedef vector<char> vech;


int main() {
	ll H,W;cin>>H>>W;
    vector<vector<char>> data(H,vech(W)),data2(2*H,vech(W));rep0(i,H){rep0(j,W){cin>>data[i][j];}}
    rep0(i,2*H){
        rep0(j,W){
            cout<<data[i/2][j];
        }
        cout<<endl;
    }
}

