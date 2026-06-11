#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD = 1000000007;


signed main(){
    int N;
    cin >> N;
    int x,y;
    int tmpx=0,tmpy=0,cnt=0;
    for(int i=0;i<N;i++){
        cin >> x >> y;
        tmpx = max(tmpx,x);
        if(tmpx == x) tmpy = y;
    }
    
    for(int i=0;i<tmpy;i++){
        cnt++;
    }
    
    cout << tmpx+cnt << endl;
    
    return 0;
}
