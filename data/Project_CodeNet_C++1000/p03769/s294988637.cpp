#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <deque>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    N++;
    int A, B;
    vector<int> ops;
    while(N != 1){
        if(N % 2 == 1){
            ops.push_back(0);
            N--;
        }else{
            N >>= 1;
            ops.push_back(1);
        }
    }
    reverse(ops.begin(), ops.end());

    int cnt = 1;
    deque<int> ans1, ans2;
    for(auto op : ops){
        if(op == 0){
            ans1.push_back(cnt);
            ans2.push_front(cnt);
        }else{
            ans1.push_back(cnt);
            ans2.push_back(cnt);
        }
        cnt++;
    }
    vector<int> ans;
    for(auto x : ans1) ans.push_back(x);
    for(auto x : ans2) ans.push_back(x);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;

    //int num = 0;
    //for(int i=1; i<(1<<ans.size()); i++){
    //    vector<int> v;
    //    for(int j=0; j<ans.size(); j++)
    //        if(i & (1<<j)) v.push_back(ans[j]);
    //    if(v.size() % 2 == 1) continue;
    //    bool flag = true;
    //    for(int j=0; j<v.size()/2; j++)
    //        if(v[j] != v[v.size()/2+j]){
    //            flag = false;
    //            break;
    //        }
    //    if(flag)
    //        num++;
    //}
    //cout << num << endl;
    return 0;
}
