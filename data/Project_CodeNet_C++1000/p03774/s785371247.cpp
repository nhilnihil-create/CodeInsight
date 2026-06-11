#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> student(n, vector<int>(2));
    for (int i=0; i<n; i++){
        cin >> student[i][0] >> student[i][1];
    }

    vector<vector<int>> distance(n, vector<int>(m));
    
    for (int j=0; j<m; j++){
        int c,d; cin>>c>>d;
        for (int i=0; i<n; i++){
            distance[i][j] = abs(student[i][0] - c) + abs(student[i][1] - d);
        }
    }
    for(int i=0; i<n; i++){
        int ans = min_element(distance[i].begin(), distance[i].end()) - distance[i].begin();
        cout << ans+1 << endl;
    }
}