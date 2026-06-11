#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    int n, x;
    cin >> n >> x;
    if(x == 1 || x == 2*n-1){
        cout << "No" << endl;
        return 0;
    }
    vector<bool> used(2*n,false);
    vector<int> ans(2*n,-1);
    ans[n] = x; ans[n+1] = x-1; ans[n-1] = x+1;
    used[x] = true; used[x-1] = true; used[x+1] = true;
    if(x+2 <= n) {
        ans[n+2] = x+2; used[x+2] = true;
    }
    if(x-2 >= 1) {
        ans[n-2] = x-2; used[x-2] = true;
    }
    int c = 1;
    for(int i = 1; i <= 2*n-1; i++){
        if(ans[i] == -1){
            while(used[c]){c++;}
            ans[i] = c;
            c++;
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= 2*n-1; i++) cout << ans[i] << endl;
    return 0;
}