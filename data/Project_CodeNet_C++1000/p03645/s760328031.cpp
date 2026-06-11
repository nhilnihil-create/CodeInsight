#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    set<int> from_s;
    set<int> to_g;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        if(a==1) from_s.insert(b);
        if(b==n) to_g.insert(a);
    }
    for(auto k:from_s){
        if(to_g.count(k)){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}