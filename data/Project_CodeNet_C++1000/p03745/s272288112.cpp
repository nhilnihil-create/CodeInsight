#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long a[100010];
    cin >> n;
    for (int i=1; i<n+1; i++){
        cin >> a[i];
    }
    int ans = 1;
    bool up = true;
    bool down = true;
    for (int i=1; i<n;){
        if (a[i+1]==a[i]){
            i++;
        }
        else if (up && a[i+1]>a[i]){
            down = false;
            i++;
        }
        else if (down && a[i+1]<a[i]){
            up = false;
            i++;
        }
        else if (!down && a[i+1]<a[i]){
            down = true;
            ans++;
            i++;
        }
        else if (!up && a[i+1]>a[i]){
            up = true;
            ans++;
            i++; 
        }
    }
    cout << ans << endl;
    return 0;
}