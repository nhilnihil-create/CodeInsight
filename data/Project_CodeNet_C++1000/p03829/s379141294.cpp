#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,a,b,now,back,tired,ans = 0;
    cin >> n >> a >> b;
    cin >> back;
    for(int i = 0;i < n - 1;i++){
        cin >> now;
        tired = (now - back) * a;
        ans += min(tired,b);
        back = now;
    }
    cout << ans << endl;
}
