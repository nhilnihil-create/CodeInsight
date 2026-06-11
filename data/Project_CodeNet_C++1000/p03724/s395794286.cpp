#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> degree(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;

        degree[a] += 1;
        degree[b] += 1;
    }

    for(int i=0; i<n; i++){
        if(degree[i] % 2 == 1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}