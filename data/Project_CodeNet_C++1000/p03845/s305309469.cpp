//2020-08-20, Thu

#include<iostream>
using namespace std;

int main(){
    int n, sum = 0, m;
    cin >> n;
    int t[n - 1];
    for (int i = 0; i < n; i++){
        cin >> t[i];
        sum += t[i];
    }
    
    cin >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        cout << (sum - (t[x - 1] - y)) << endl;
    }

    return 0;
}