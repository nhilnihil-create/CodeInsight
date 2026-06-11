#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main(){
    int n, m;
    cin >> n;
    vector<int> time(n);
    for(int i = 0; i < n; i++){
        cin >> time[i];
    }
    cin >> m;
    vector<p> drink;
    for(int i = 0; i < m; i++){
        int y, x;
        cin >> y >> x;
        drink.push_back(p(y, x));
    }

    for(p z : drink){
        int ans = 0;
        for(int j = 0; j < n; j++){
            if(z.first == j + 1) ans += z.second;
            else ans += time[j];
        }
        cout << ans << endl;
    }
}