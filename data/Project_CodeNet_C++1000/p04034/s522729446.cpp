#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int n,m;
    int ans=0;
    cin >> n >> m;
    vector<int> hako(n,1);
    vector<bool>hakof(n,false);
    hakof[0] = true;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        hako[a]--; hako[b]++;
        if(hakof[a] == true) hakof[b] = true;
        if(hako[a] == 0) hakof[a] = false;
    }
    rep(i,n){
        if(hako[i]>0 && hakof[i] == true) ans++;
    }
    cout << ans << endl;

    
}