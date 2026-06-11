#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n, k;
    cin >> n >> k;
    int a[n+1];
    srep(i,1,n+1)cin >> a[i];
    int ans = 0;
    if(a[1] != 1){
        ans++; a[1] = 1;
    }

    int c[n + 1] = {};
    srep(i,1,n+1)c[a[i]]++;
    int f[n + 1] = {};
    queue<int> que;
    srep(i,2,n+1){
        if(c[i] == 0){
            f[i] = 1;
            que.push(i);
        }
    }

    while(que.size() > 0){
        int x = que.front(); que.pop();
        if(a[x] == 1)continue;
        if(f[x] == k){
            ans++;
            c[a[x]]--;
            if(c[a[x]] == 0){
                f[a[x]] = max(1, f[a[x]]);
                que.push(a[x]);
            }
            a[x] = 1;
        }else{
            f[a[x]] = max(f[a[x]], f[x]+1);
            c[a[x]]--;
            if(c[a[x]] == 0){
                f[a[x]] = max(1, f[a[x]]);
                que.push(a[x]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
 
 
