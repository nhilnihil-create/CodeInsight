#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cities(n);
    vector<int> vec(m * 2);
    for(int i = 0; i < m * 2; i++){
        cin >> vec[i];
        cities[vec[i] - 1] += 1;
    }
    
    rep(i, n){
        cout << cities[i] << endl;
    }
    
}