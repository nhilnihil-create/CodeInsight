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
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        b.push_back(make_pair(x,y));
    }

    for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
            if(j == b[i].first - 1) suma += b[i].second;
            else suma += a[j];
        }
        cout << suma << endl;
        suma = 0;
    }
        
        
    return 0;
}