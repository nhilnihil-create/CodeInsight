#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> C(n + 1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        C[a]++;
        C[b]++;
    }

    for (const auto &c: C){
        if (c & 1){
            puts("NO");
            return 0;
        }
    }

    puts("YES");
}