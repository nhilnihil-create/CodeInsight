#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
int main(void){
    int n, size = 0;
    vector<int> a;
    vector<P> p;
    vector<long long> ans;
    cin >> n;
    a.assign(n, 0);
    ans.assign(n, 0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        p.push_back(P(a[i], i));
    }
    sort(p.begin(), p.end(), greater<P>());
    int tg = n;
    for(int i=0;i<n;i++){
        size++;
        while(i+1 < n && p[i+1].first == p[i].first){
            i++;
            size++;
        }
        tg = min(tg, p[i].second);
        if(i == n-1){
            ans[tg] += (long long)p[i].first * size;
            break;
        }
        ans[tg] += (long long)(p[i].first - p[i+1].first) * size;
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << endl;
    }
}
