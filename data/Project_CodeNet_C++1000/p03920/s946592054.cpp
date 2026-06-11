#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;

using namespace std;

int main(){
    int N;
    int k = 0;
    cin >> N;
    while(k * (k + 1) < 2 * N){
        k ++;
    }
    int rm = k * ( k + 1) / 2 - N;
    for(int i = 1; i <= k; i ++){
        if(i != rm){
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
