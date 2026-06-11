#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int a[3];
    int count[110] = {0};
    int ans = 0;
    for(int i = 0; i < 3; i++){
        cin >> a[i];
        ++count[a[i]];
    }
    for(int i = 0; i < 110; i++)
        if(count[i] != 0) ans++;
    cout << ans << endl;
    
    return 0;
}