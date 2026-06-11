#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    vector<bool> s(200100); //1とi
    vector<bool> t(200100); //iとn がつながってる
    bool ok=false;
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        if(a==1) s[b] = true;
        if(b==n) t[a] = true;
    }
    for(int i=1; i<=n; i++){
        if(s[i] == true && t[i] == true) ok=true;
    }
    if(ok) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;

}