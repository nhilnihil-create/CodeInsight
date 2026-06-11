#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int N;
    cin >> N;
    int cnt = 0;
    set<int> v;
    rep(i, 0, N){
        int tmp;
        cin >> tmp;
        if(tmp>=3200) {cnt++;
            
        }else{
            int colorN = tmp/400;
            v.insert(colorN);
        }
    }
    int minv = v.size();
    int maxv = minv+cnt;
    minv = max(minv,1);
    cout << minv << " " << maxv << endl;
    return 0;
}