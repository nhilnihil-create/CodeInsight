#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stack>
#include <queue>
#include <set>

#define rep(i,n) for(int i=0;i<n;i++)

typedef long long ll;
using namespace std;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    if(a[a.size()-1]==b[0] && b[b.size()-1]==c[0]) cout << "YES";
    else cout << "NO";
    return 0;
}