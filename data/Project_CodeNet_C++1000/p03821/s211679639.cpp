#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    long long int ans = 0;
    for(int i = n-1; i >= 0; i--){
        if((a[i]+ans)%b[i] != 0){
            ans += b[i] - (a[i]+ans)%b[i];
        }
    }
    cout << ans << endl;
    return 0;
}
