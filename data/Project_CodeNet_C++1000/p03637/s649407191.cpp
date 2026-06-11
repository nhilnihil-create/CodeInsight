#include <bits/stdc++.h>
using namespace std;

#define lint long long


int main(){
    int N; cin >> N;
    vector<int> a(N), b(N);
    map<int, int> cnt;
    for(int i = 0; i < N; ++i){
        cin >> a[i];
        if(a[i]%4 == 0){
            b[i] = 2;
            cnt[2]++;
        } else if(a[i]%2 == 0){
            b[i] = 1;
            cnt[1]++;
        } else {
            b[i] = 0;
            cnt[0]++;
        }
    }
    if(cnt[0] > cnt[2]){
        if(cnt[1] == 0 && cnt[0] == cnt[2] + 1){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "Yes" << endl;
    }
    
}
