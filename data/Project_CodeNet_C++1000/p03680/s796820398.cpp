/*
      author  : nishi5451
      created : 14.08.2020 13:18:13
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<bool> dp(n+1,false);
    for(int i=1; i<=n; i++) cin >> a[i];
    int now = a[1];
    for(int i=1; i<=n+3; i++){
        if(now == 2){
            cout << i << endl;
            return 0; 
        }
        now = a[now];
    }
    cout << -1 << endl;

    return 0;
}