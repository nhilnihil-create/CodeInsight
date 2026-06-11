#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<limits>
#include<ctime>
#include<stack>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m = 0, ans = 0;
    for(int i=0;i<n;i++){
        m += a[i];
    }
    if((m*10 / n) % 10 >= 5)m = m / n + 1;
    else m = m / n;
    for(int i=0;i<n;i++){
        ans += pow(a[i] - m, 2);
    }
    cout << ans << endl;
}