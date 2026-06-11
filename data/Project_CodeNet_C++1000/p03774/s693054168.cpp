#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m, x, y, s = 0, _s, p;
    vector<int> vx, vy;

    cin >> n >> m;
    for(int i = 0; i < n + m; i++){
        cin >> x >> y;
        vx.emplace_back(x);
        vy.emplace_back(y);
    }

    for(int i = 0; i < n; i++){
        for(int j = n; j < n + m; j++){
            _s = abs(vx[i] - vx[j]) + abs(vy[i] - vy[j]);
            if(s > _s || j == n){
                s = _s;
                p = j - n + 1;
            }
        }
        cout << p << endl;
    }
}