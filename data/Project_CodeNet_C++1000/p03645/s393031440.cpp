#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, n1; cin >> n >> n1;
    bool arr[n];
    memset(arr, false, sizeof(arr));
    bool res = false;
    for(int i=0;i<n1; i++){
        int x, y; cin >> x >> y;
        if(x == 1){
            if(arr[y]) res = true;
            arr[y] = true;
        }
        else if(y == n){
            if(arr[x]) res = true;
            arr[x] = true;
        }
    }
    if(res) cout << "POSSIBLE"<< endl;
    else cout << "IMPOSSIBLE"<< endl;


    return 0;
}
