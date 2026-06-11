#include<bits/stdc++.h>


#define fi first
#define se second
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define pb push_back
#define len(x) (int)(x).size()
#define mkp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;


const int maxn = 3e5 + 10 , inf = 1e9;
int fen[maxn];
int get(int pos){
    int ans = 0;
    for(;pos > 0 ;pos -= (pos & -pos))
        ans += fen[pos];
    return ans;
}
void add(int x , int val){
    for(;x < maxn; x += (-x & x)){
        fen[x]+= val;
    }
}
void modify(int l , int r){
    add(l ,   +1);
    add(r+1 , -1);
}
vector < int > line[maxn];
signed main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , m;cin >> n >> m;
    vector < pii > lines(n);
    for(auto &i : lines)cin >> i.fi >> i.se;
    for(int i = 0 ; i < len(lines); ++i){
        line[lines[i].se-lines[i].fi+1].pb(lines[i].fi);
    }
    int muchlonger = n;
    for(int i = 1; i <= m; ++i){
        int pos = 0;

        int ans = muchlonger;
        while(pos <= m){
            ans += get(pos);
            pos += i;
        }
        for(auto l : line[i]){
            int r = l + i - 1;
            modify(l , r);
            muchlonger--;
        }
        cout << ans << '\n';
    }

    return 0;
}
