#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(200000), b(200000);
    set<int> st, go;
    for(int i=0; i<m; i++){
        cin >> a[i] >> b[i];
        if(a[i]==1 || b[i]==1){
            if(a[i]==1) st.insert(b[i]);
            if(b[i]==1) st.insert(a[i]); 
        }else if(a[i]==n || b[i]==n){
            if(a[i]==n) go.insert(b[i]);
            if(b[i]==n) go.insert(a[i]);
        }
    }
    for(int i=2; i<n; i++){
        if(st.count(i) && go.count(i)){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}