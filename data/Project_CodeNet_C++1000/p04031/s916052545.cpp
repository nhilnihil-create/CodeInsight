#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 1001001001;
    for(int i = -100; i <= 100; i++){
        int coans = 0;
        for(int j = 0; j < n; j++){
            coans += (a[j]-i)*(a[j]-i);
        }
        if(ans > coans) ans = coans;
    }
    cout << ans << endl;
    return 0;
}