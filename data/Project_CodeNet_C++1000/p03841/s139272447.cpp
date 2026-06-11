#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<int, i_i> i_i_i;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    int x[520];
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    vector<i_i_i> before, after;
    for(int i = 2; i <= n; i++){
        before.push_back({x[i], {i - 1, i}});
    }
    for(int i = 1; i < n; i++){
        after.push_back({x[i], {n - i, i}});
    }
    bool finished[520];
    for(int i = 2; i <= n; i++){
        finished[i] = false;
    }
    finished[1] = true;
    vector<i_i> now;
    for(int i = 1; i <= n; i++){
        now.push_back({x[i], i});
    }
    sort(before.begin(), before.end());
    sort(after.begin(), after.end());
    sort(now.begin(), now.end());
    int IndexBefore = 0;
    int IndexAfter = 0;
    int IndexNow = 0;
    for(int i = 0; i < now.size() - 1; i++){
        if(now[i].first == now[i + 1].first){
            cout << "No" << endl;
            return 0;
        }
    }
    int ans[250500];
    for(int index = 1; index <= n * n; index++){
        //cout << index - 1 << " " << ans[index - 1] << endl;
        if(IndexNow < n){
            if(now[IndexNow].first == index){
                if(finished[now[IndexNow].second]){
                    ans[index] = now[IndexNow].second;
                    IndexNow++;
                    continue;
                }
                cout << "No" << endl;
                return 0;
            }
        }
        if(IndexBefore < n - 1){
            ans[index] = before[IndexBefore].second.second;
            before[IndexBefore].second.first--;
            if(before[IndexBefore].second.first == 0){
                finished[before[IndexBefore].second.second] = true;
                IndexBefore++;
            }
            continue;
        }
        if(IndexAfter >= n - 1){
            cout << "No" << endl;
            return 0;
        }
        if(after[IndexAfter].first >= index){
            cout << "No" << endl;
            return 0;
        }
        ans[index] = after[IndexAfter].second.second;
        after[IndexAfter].second.first--;
        if(after[IndexAfter].second.first == 0){
            IndexAfter++;
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n * n; i++){
        cout << ans[i];
        if(i < n * n){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
