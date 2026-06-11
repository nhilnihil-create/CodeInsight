#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    int n,m;
    cin >> n >> m;

    vector <bool> s(n,false), g(n,false);


    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        if(a==1){
            s[b-1]=true;
        }
        if(b==n){
            g[a-1]=true;
        }
    }

    bool ok=false;

    for(int i=0; i<n; i++){
        if(s[i]){
            if(g[i]){
                ok=true;
                break;
            }
        }
        if(ok) break;
    }



    if(ok) cout << "POSSIBLE" <<endl;
    else cout << "IMPOSSIBLE" << endl;
}