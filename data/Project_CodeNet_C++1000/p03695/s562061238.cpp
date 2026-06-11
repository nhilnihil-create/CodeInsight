#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int>a(N);
    set<int>Set;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        int X = a[i]/400;
        if(a[i]/400 >= 8) {
            ans++;
        }
        else {
            Set.insert(X);
        }
    }
    if(Set.size() == 0) {
        cout << 1 << " "<< ans << endl;
    }
    else {
        cout << Set.size() << " " << ans+Set.size() << endl;
    }
}