#include <iostream>
#include <vector>
using namespace std;
const int lim = 100005;
int main(){
    int n;
    cin >> n;
    vector<int> a(lim, 0);
    for(int i = 0; i < n; i++){
        int a1;
        cin >> a1;
        a[a1]++;
    }
    for(int i = 0; i < lim; i++){
        if(a[i] != 0){
            a[i] = 2-a[i]%2;
        }
    }
    
    int twonum = 0;
    int ans = 0;
    for(int i = 0; i < lim; i++){
        if(a[i] == 2) twonum++;
        if(a[i] != 0) ans++;
    }

    if(twonum % 2) ans--;
    cout << ans << endl;
    return 0;
}