#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m, x,y,suma = 0;
    vector<int> a;
    cin >> n;   
    for(int i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
        suma += x;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        cout << suma - (a[x-1] - y) << endl;
    }

        
    return 0;
}