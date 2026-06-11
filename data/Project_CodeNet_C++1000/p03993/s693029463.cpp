#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 1;i <= n;i++)cin >> a[i];
    
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(i == a[a[i]])ans++;
    }
    cout << ans/2 << endl;
    return 0;
}
