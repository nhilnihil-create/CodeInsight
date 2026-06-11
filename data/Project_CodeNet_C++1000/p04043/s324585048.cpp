#include<iostream>
using namespace std;
int main() {
    int cnt1,cnt2;
    cnt1 = cnt2 = 0;
    int x;
    for(int i = 1; i <= 3; ++i) {
        cin >> x;
        if(x == 5) cnt1++;
        else if(x == 7) cnt2++;
    }
    if(cnt1 == 2 && cnt2 == 1) {
        cout << "YES\n";
    } else cout << "NO\n";
return 0;
}