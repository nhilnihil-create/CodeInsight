#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    
    vector<int> vec(n * 2);
    rep(i, n * 2){
        cin >> vec[i];
    }
    
    int sum = 0;
    for(int i = 0; i < n * 2; i += 2){
        sum += vec[i+1] - vec[i] + 1;
    }
    cout << sum << endl;
    
}