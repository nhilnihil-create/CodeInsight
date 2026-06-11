#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100010;

int n, a[NMAX], ret;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    ret = 1;
    bool isup = false;
    bool isdown = false;
    for (int i=2; i<=n; i++){
        if(!isup && !isdown && a[i-1] < a[i]){
            isup = true;
        }else if(!isup && !isdown && a[i-1] > a[i]){
            isdown = true;
        }else if(!isup && isdown && a[i-1] < a[i]){
            ret++;
            isdown = false;
        }else if(isup && !isdown && a[i-1] > a[i]){
            ret++;
            isup = false;
        }
    }
    cout << ret;
    return 0;
}
