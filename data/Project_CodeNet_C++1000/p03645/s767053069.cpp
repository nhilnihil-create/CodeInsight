#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a,b;
    cin >> n >> m;
    set<int> s_relay,g_relay;
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        if(a == 1)s_relay.insert(b);
        if(b == n)g_relay.insert(a);
    }
    for(int p : s_relay){
        if(g_relay.count(p)){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}