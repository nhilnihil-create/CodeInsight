#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, n;
    cin >> h >> w >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<vector<int>> c(h, vector<int>(w));
    int x=0, y=0;
    for(int i=0; i<n; i++){
        //cout << "a[" << i << "] = " << a[i] << endl;
        while(a[i] > 0){
            //cout << "x = " << x << ", y = " << y << endl;
            c[x][y] = i+1;
            a[i] -= 1;
            if(y % 2 == 0 && x < h-1) x += 1;
            else if(y % 2 != 0 && x > 0) x -= 1;
            else y += 1;
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}