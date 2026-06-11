#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    int n;
    cin >> n;
    vector <long long> a(n);
    rep(i,n) cin >> a[i];

    if(n==1){
        cout << 1 << endl;
        return 0;
    }

    vector <int> b(n-1);

    for(int i=0; i<=n-2; i++){
        if((a[i+1]-a[i])>0){
            b[i] = 1;
        }
        else if((a[i+1]-a[i]) == 0){
            b[i] = 0;
        }
        else{
            b[i] = -1;
        }
    }
    
    int tmp = b[0];
    int ans = 1;
    for(int i=1; i<n-1; i++){
        if(tmp == 0){
            if(b[i] == 1){
                tmp = 1;
            }
            if(b[i] == -1){
                tmp = -1;
            }
        }
        if(tmp == 1){
            if(b[i] == -1){
                ans++;
                if(i+1<n){
                    tmp = b[i+1];
                }
            }
        }
        if(tmp == -1){
            if(b[i] == 1){
                ans++;
                if(i+1<n){
                    tmp = b[i+1];
                }
            }
        }
    }
    cout << ans << endl;

}
