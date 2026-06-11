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



int main(){
    int n;cin >> n;
    vector<P> x(n);
    vector<int> ans(n*n,0);
    for (int i = 0; i < n; i++) {
        int X;cin >> X;
        X--;
        x[i] = mp(X,i+1);
        ans[X] = i+1;
    }
    sort(ALL(x));
    vector<int> c(n,1);
    int l = 0,r = 0;
    for (int i = 0; i < n*n; i++) {
        if(ans[i]) continue;
        while(r < n && c[r] == x[r].second){
            r++;
        }
        while(l < n && c[l] == n){
            l++;
        }
        if(r == n){
            ans[i] = x[l].second;
            c[l]++;
        }
        else{
            ans[i] = x[r].second;
            c[r]++;
        }
    }
    vector<int> s(n,0);
    int k = 0;
    for (int i = 0; i < n*n; i++) {
        s[ans[i]-1]++;
        if(k < n && x[k].first == i){
            if(s[x[k].second-1] != x[k].second){
                puts("No");
                return 0;
            }
            k++;
        }
    }
    puts("Yes");
    for (int i = 0; i < n*n; i++) {
        cout << ans[i] << (i==n*n-1?"\n":" ");
    }
    return 0;
}
