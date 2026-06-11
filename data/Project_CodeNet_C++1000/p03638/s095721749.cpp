#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int c[h][w];
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<a[i]; j++){
            int p = cnt/w;
            int q = cnt%w;
            if(p%2 == 0){
                c[p][q] = i+1;
            }
            else{
                c[p][w-1-q] = i+1;
            }
            cnt++;
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
