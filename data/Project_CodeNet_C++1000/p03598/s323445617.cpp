#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n, k, dis = 0;
    cin >> n >> k;
    vector<int> x(n);
    for (int i=0; i<n; i++) cin >> x[i];
    for (int i=0; i<n; i++){
        if (x[i] <= k - x[i]){
            dis += x[i] * 2;
        } else {
            dis += (k - x[i]) * 2;
        }
    }
    cout << dis << endl;
    return 0;
}