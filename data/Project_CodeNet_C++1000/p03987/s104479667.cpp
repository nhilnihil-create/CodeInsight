#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

vector<int> get_next_seq(vector<int>& arr) { // // O(n) by using stack
    int n = arr.size();
    vector<int> st;
    vector<int> nxt(n, n);
    /* ref here
    "GT": auto cmp_func = [](const int& a, const int& b) {return a > b;};
    "GE": auto cmp_func = [](const int& a, const int& b) {return a >= b;};
    "LT": auto cmp_func = [](const int& a, const int& b) {return a < b;};
    "LE"  auto cmp_func = [](const int& a, const int& b) {return a <= b;}; */
    auto cmp_func = [](const int& a, const int& b) {return a < b;};
    for(int i = 0; i < n; i++) {
        while (!st.empty() && cmp_func(arr[i], arr[st.back()])) {
            nxt[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return nxt;
}
vector<int> get_prev_seq(vector<int>& arr) { // O(n) by using stack
    int n = arr.size();
    vector<int> st;
    vector<int> pre(n, -1);
    /* ref here
    "GT": auto cmp_func = [](const int& a, const int& b) {return a > b;};
    "GE": auto cmp_func = [](const int& a, const int& b) {return a >= b;};
    "LT": auto cmp_func = [](const int& a, const int& b) {return a < b;};
    "LE"  auto cmp_func = [](const int& a, const int& b) {return a <= b;}; */
    auto cmp_func = [](const int& a, const int& b) {return a < b;};
    for(int i = n-1; i >= 0; i--) {
        while (!st.empty() && cmp_func(arr[i], arr[st.back()])) {
            pre[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return pre;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(auto& val: arr)
        cin >> val;
    auto nxt = get_next_seq(arr);
    auto pre = get_prev_seq(arr);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += ll(nxt[i]-i) * ll(i - pre[i]) * ll(arr[i]);
    }
    cout << ans << endl;

    return 0;
}


