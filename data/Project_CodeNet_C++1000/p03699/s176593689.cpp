#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    int sum = 0;
    for(int i = 0; i < n; i++) sum += s[i];

    if(sum % 10 != 0) cout << sum << endl;
    else{
        int ans = 0;
        for(int i = 0; i < n; i++){
            if((sum-s[i])%10 != 0 && sum-s[i] > ans) ans = sum-s[i];
        }
        cout << ans << endl;
    }
    return 0;
}