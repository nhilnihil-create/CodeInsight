#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N, x;
    cin >> N >> x;
    long long all = 2 * N - 1;
    long long mid = (all + 1) / 2;
    set<long long> use;
    for(long long i = 1; i <= all; i++)use.insert(i);
    if(N == 2){
        if(x == 2){
            cout << "Yes" << '\n';
            for(long long i = 1; i <= all; i++){
                cout << i << '\n';
            }
        }else{
            cout << "No" << '\n';
        }
    }else if(x == 1 || x == all){//3 <= N
        cout << "No" << '\n';
    }else{
        cout << "Yes" << '\n';
        vector<long long> ans(all, -1);
        if(x == 2){
            ans[mid - 2] = x + 1;
            ans[mid - 1] = x;
            ans[mid] = x - 1;
            ans[mid + 1] = x + 2;
            use.erase(x + 1);
            use.erase(x);
            use.erase(x - 1);
            use.erase(x + 2);
            for(long long i = 0; i < all; i++){
                if(ans[i] != -1)continue;
                ans[i] = *rbegin(use);
                use.erase(ans[i]);
            }
            for(auto a : ans){
                cout << a << '\n';
            }
        }else{
            ans[mid - 2] = x - 1;
            ans[mid - 1] = x;
            ans[mid] = x + 1;
            ans[mid + 1] = x - 2;
            use.erase(x - 1);
            use.erase(x);
            use.erase(x + 1);
            use.erase(x - 2);
            for(long long i = 0; i < all; i++){
                if(ans[i] != -1)continue;
                ans[i] = *rbegin(use);
                use.erase(ans[i]);
            }
            for(auto a : ans){
                cout << a << '\n';
            }
        }
    }
    return 0;
}