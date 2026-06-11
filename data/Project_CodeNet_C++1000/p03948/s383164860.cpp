#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main(){
    int n, t, maxn = 0;
    cin >> n >> t;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    b[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
        b[i] = max(b[i+1], a[i]);
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(maxn < b[i]-a[i]){
            maxn = b[i] - a[i];
            cnt = 1;
        }else if(maxn == b[i] - a[i]){
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}
