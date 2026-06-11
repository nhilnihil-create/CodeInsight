#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    int a[N];
    map<int, int> mp;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        mp[a[i]] = i;
    }

    int cnt = 0;

    sort(a, a + N);

    for(int i = 0; i < N; i++){
        int dis = abs(mp[a[i]] - i);
        if(dis % 2 != 0) cnt++;
    }

    cout << (cnt + 1) / 2 << endl;
    return 0;
}