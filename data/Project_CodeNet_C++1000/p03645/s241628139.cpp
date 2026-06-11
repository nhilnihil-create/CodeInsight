#include <bits/stdc++.h>
using namespace std;

long long n,m,c,x,y,a,b, hasil, tag;
int arr[200001];
bool mulai[200001];
bool sel[200001];
bool valid;

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++){
        cin >> x >> y;
        if (x == 1){
            mulai[y] = true;
        }
        if (y == m){
            sel[x] = true;
        }
    }
    valid = false;
    for (int i = 1; i <= m; i++){
        if (mulai[i] && sel[i]){
            valid = true;
        }
    }
    if (valid == true){
        cout << "POSSIBLE" << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
}
    
    
    
    

    
   
