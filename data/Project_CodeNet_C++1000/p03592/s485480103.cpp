#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    rep(i, N+1){
        rep(j, M+1){
            int ans = i*(M-j) + j*(N-i);
            if(ans == K){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}