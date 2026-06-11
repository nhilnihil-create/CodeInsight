#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, p;
    cin >> n >> p;
    vector<int> a(n+1);

    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<long long int>> memo(n+1, vector<long long int>(2, 0));
    memo[0][0] = 1;
    if(a[0]%2) memo[0][1] = 1;
    else memo[0][0] += 1;
    for(int i = 1; i < n; i++){
        memo[i][0] = (a[i]%2) ? memo[i-1][1]+memo[i-1][0] : memo[i-1][0]*2;
        memo[i][1] = (a[i]%2) ? memo[i-1][0]+memo[i-1][1] : memo[i-1][1]*2;
    }

    cout << memo[n-1][p] << endl;
    return 0;
}