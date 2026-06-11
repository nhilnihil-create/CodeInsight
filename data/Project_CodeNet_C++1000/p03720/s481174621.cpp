#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i, n) for(i=1; i<=n; i++)
using namespace std;
int main() {
    int n, m, i;
    cin >> n >> m;
    //map<int, int> roads;
    vector<int> roads(n, 0);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        roads[a-1]++;
        roads[b-1]++;
    }
    for(auto it = roads.begin(); it!=roads.end(); it++){
        cout << *it << "\n";
    }
    return 0;
}