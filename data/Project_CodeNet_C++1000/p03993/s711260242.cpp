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
    int N;
    cin >> N;
    int a[N];
    rep(i, N) cin >> a[i];
    int cnt = 0;
    rep(i, N){
        if((i + 1) == a[a[i] - 1]){
            cnt++;
        }
    }
    cout << cnt / 2 << endl;
    return 0;
}