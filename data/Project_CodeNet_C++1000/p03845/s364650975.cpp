#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m, x,y,suma = 0;
    vector<pair<int,int>> b;
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
        b.push_back(make_pair(x,y));
    }

    for(int i = 0; i < m;i++){
        y = a[b[i].first - 1] - b[i].second;
        cout << suma - y << endl;
    }
        
        
    return 0;
}