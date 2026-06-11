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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};




int main(){
    int n,k;cin >> n >> k;
    vector<int> a(n),c(n,1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - k; i++) {
        c[i] = 0;
    }
    LL ans = LINF;
    do{
        LL t = 0, now = a[0];
        for (int i = 1; i < n; i++) {
            if(c[i]){
                if(now < a[i]){
                    now = a[i];
                }
                else{
                    now++;
                    t += now - a[i];
                }
            }
            else{
                if(now < a[i]) now = a[i];
            }
        }
        ans = min(ans, t);
    }while(next_permutation(ALL(c)));
    cout << ans << endl;
    return 0;
}
