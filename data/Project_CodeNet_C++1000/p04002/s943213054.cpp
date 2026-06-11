#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;
set<pair<int, int> > st;
ll ans[10];
ll h, w;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

void check(int a, int b)
{
    if((a < 2) || (a > h - 1) || (b < 2) || (b > w - 1)){
        return;
    }
    int number = 0;
    for(int i = a - 1; i <= a + 1; i++){
        for(int j = b - 1; j <= b + 1; j++){
            pair<int, int> in;
            in.first = i;
            in.second = j;
            if(st.count(in) > 0){
                number++;
            }
        }
    }
    ans[number]--;
    ans[number + 1]++;
    return;
}

int main() {
    int n;
    cin >> h >> w >> n;
    for(int i = 0; i < 10; i++){
        ans[i] = 0;
    }
    ans[0] = (h - 2) * (w - 2);
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        for(int j = -1; j <= 1; j++){
            for(int k = -1; k <= 1; k++){
                check(a + j, b + k);
            }
        }
        pair<int, int> in;
        in.first = a;
        in.second = b;
        st.insert(in);
    }
    for(int i = 0; i < 10; i++){
        cout << ans[i] << endl;
    }
    return 0;
}