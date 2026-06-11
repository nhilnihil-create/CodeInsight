#include <bits/stdc++.h>

typedef long long ll;
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define REP(i,n) for (int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
 
using namespace std;

int main(){

    int n;
    cin >> n;
    int p[n];
    REP(i,n) cin >> p[i];

    int now = 0;
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(now == 0 && p[i] == i+1){
            now++;
        }else if(now == 1){
            ans++;
            now = 0;
        }
    }
    if(now == 1)ans++;
    cout << ans;
    
}
