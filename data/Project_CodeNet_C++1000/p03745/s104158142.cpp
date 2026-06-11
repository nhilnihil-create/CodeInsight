#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 1;
    bool isup = false;
    bool isdown = false;
    for(int i = 1; i < n; i++){
        if(!isup && !isdown && a[i-1] < a[i]){
            isup = true;
        }else if(!isup && !isdown && a[i-1] > a[i]){
            isdown = true;
        }else if(!isup && isdown && a[i-1] < a[i]){
            ans++;
            isdown = false;
        }else if(isup && !isdown && a[i-1] > a[i]){
            ans++;
            isup = false;
        }
    }
    cout << ans << endl;
    return 0;
}