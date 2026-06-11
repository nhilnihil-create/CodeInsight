#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using vvv= vector<vv>;

int main(){
    vi a(3);
    rep(i,3)cin>>a[i];
    rep(i,3){
        if(a[i]%2==0)continue;
        cout << 0 << endl;
        return 0;
    }
    
    sort(a.begin(), a.end());
    
    vi b(2);
    rep(i,2){
        b[i] = a[i+1] - a[i];
    }
    
    sort(b.begin(), b.end());
    
    if(b[1]==0){
        cout << -1 << endl;
        return 0;
    }
    
    int ans = 0;
    
    if(b[0]==0){
        while(b[1]%2==0){
            ans++;
            b[1] /= 2;
        }
    }else{
        
        while(b[1]%b[0]!=0){
            b[1] %= b[0];
            swap(b[1],b[0]);
        }
        while(b[0]%2==0){
            ans++;
            b[0] /= 2;
        }
    }
    cout << ans << endl;
    return 0;
}