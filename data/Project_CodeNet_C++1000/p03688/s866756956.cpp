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
typedef long long ll;
using namespace std;

int main(){
    int N;
    cin >> N;
    map<int, int> cnt;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        cnt[a]++;
    }

    int sz = cnt.size();
    string ans;

    if(sz == 1){
        auto it = cnt.begin();
        int num = it -> first;

        if(num * 2 <= N || num + 1 == N) ans = "Yes";
        else ans = "No";
    }

    else if(sz == 2){
        auto it = cnt.begin();
        int n1 = it -> first;
        it++;
        int n2 = it -> first;

        int mn = min(n1, n2);
        int mx = max(n1, n2);

        int rest = mx - cnt[mn];
        int restcnt = N - cnt[mn];
        if(mn + 1 == mx && rest > 0){
            if(restcnt >= rest * 2){
                ans = "Yes";
            }
            else {
                ans = "No";
            }
        }
        else {
            ans = "No";
        }
    }

    else {
        ans = "No";
    }

    cout << ans << endl;
    return 0;
}
