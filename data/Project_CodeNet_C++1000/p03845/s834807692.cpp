#include<iostream>
#include<algorithm>
#include<vector>
#define mp make_pair
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> t;
    int i;
    for(i=0; i<n; i++){
        int x;
        cin >> x;
        t.push_back(x);
    }
    int m;
    cin >> m;
    //vector<pair<int, int>> drinks;
    for(i=1; i<=m; i++){
        int p, x;
        cin >> p >> x;
        int tim = x;
        for(int j=0; j<n; j++){
            if(j==(p-1)) continue;
            else tim += t[j];
        }
        cout << tim << endl;
    }
    return 0;
}