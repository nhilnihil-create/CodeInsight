#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int p[100020];
    for(int i = 0;i < n;i++)cin >> p[i],p[i]--;
    bool b[100020]{};
    for(int i = 0;i < n;i++){
        b[i] = (p[i] == i);
    }
    int ans = 0;

    if(b[n-1] | b[n-2])b[n-1] = b[n-2] = false,ans++;
    for(int i = 0;i < n-1;i++){
        if(b[i])b[i] = b[i+1] = false,ans++;
    }
    cout << ans << endl;
}