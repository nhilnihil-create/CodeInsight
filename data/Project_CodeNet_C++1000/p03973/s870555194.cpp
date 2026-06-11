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
    int n;cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL now = 2;
    LL ans = a[0] - 1;
    for (int i = 1; i < n; i++) {
        if(a[i] == now) now++;
        else{
            ans += (a[i] - 1)/ now;
        }
    }
    cout << ans << endl;
    return 0;
}
