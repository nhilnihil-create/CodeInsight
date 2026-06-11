#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque> 
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype> 
using namespace std;

int main(){
    int W, a, b;
    cin >> W >> a >> b;
    int cnt=0;
    int c=0;
    if (a+W<b) c=abs(a+W-b);
    else c=abs(b+W-a);
    if ((a<=(b+W) && (b+W)<=(a+W)) || (a<=b && b<=(a+W))) {
        cout << 0 << endl;
        return 0;
    }
    for (int i=0; i<c; i++) {
        cnt++;
    }
    cout << cnt << endl;
}