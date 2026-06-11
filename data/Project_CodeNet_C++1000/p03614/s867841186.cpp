#include <bits/stdc++.h>
#define N int(2e5+5)
#define mod 1000000007
using namespace std;
typedef long long ll;
ll ans;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++){
        if(arr[i] == i+1){
            ans++;
            if(arr[i+1] == i+2) i++;
        }
    }
    cout << ans << endl;
    return 0;
}