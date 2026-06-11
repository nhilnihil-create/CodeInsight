#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m, a, b;
    cin >> n >> m;
    vector<int> roads(n, 0);
    for (int i=0; i<m; i++){
        cin >> a >> b;
        roads[a-1]++;
        roads[b-1]++;
    }
    for (int i=0; i<n; i++){
        cout << roads[i] << endl;
    }
    return 0;
}