#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
ll rnum, bnum;
ll num[3];
int main() {
    int i = 0;
    for(;i < 3; ++i)cin >> num[i];
    ll mn = 1e19;
    for(i = 0; i < 3; ++i){
        rnum = num[i%3]/2 * num[(i+1)%3] * num[(i+2)%3];
        bnum = (num[i%3] - num[i%3]/2) * num[(i+1)%3] * num[(i+2)%3];
        mn = min(llabs(rnum - bnum), mn);
    }
    cout << mn << endl;
    return 0;
}
