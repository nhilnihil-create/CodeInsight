#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};



int main(){
    LL h,w;cin >> w >> h;
    vector<P> v(h+w);
    for (int i = 0; i < w; i++) {
        cin >> v[i].fs;
        v[i].sc = 0;
    }
    for (int i = 0; i < h; i++) {
        cin >> v[i+w].fs;
        v[i+w].sc = 1;
    }
    sort(ALL(v));
    LL ans = 0;
    LL a = w + 1, b = h + 1;
    for (int i = 0; i < h+w; i++) {
        if(v[i].sc == 1){
            ans += v[i].fs * a;
            b--;
        }
        else{
            ans += v[i].fs * b;
            a--;
        }
    }
    cout << ans << endl;
    return 0;
}
