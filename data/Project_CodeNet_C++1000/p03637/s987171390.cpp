#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int>a(N);
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(a[i]%4 == 0) {
            cnt1++;
        }
        else if(a[i]%2 == 0) {
            cnt2++;
        }
        else {
            cnt3++;
        }
    }
    if(cnt3+min(1,cnt2)-1 <= cnt1) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
