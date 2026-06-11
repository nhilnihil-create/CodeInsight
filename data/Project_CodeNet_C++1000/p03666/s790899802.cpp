#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    for (int i = 0; i < n; ++ i) {
        long long m1=a+c*i-d*(n-1-i);
        long long m2=a+d*i-c*(n-1-i);
        if (m1<=b&&b<=m2) {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
