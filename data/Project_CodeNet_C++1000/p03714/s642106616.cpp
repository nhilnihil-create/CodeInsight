#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int main(){
    long long n;
    cin >> n;
    vector<long long> a(3 * n);
    for(int i = 0; i < 3 * n; ++i) cin >> a[i];
    multiset<long long> st;
    vector<long long> mx(3 * n);
    long long sum = 0;
    for(int i = 0; i < 3 * n; ++i){
        sum += a[i];
        st.insert(a[i]);
        if(st.size() < n) continue;
        if(st.size() > n){
            auto f = st.begin();
            sum -= *f;
            st.erase(f);
        }
        mx[i] = sum;
    }
    sum = 0;
    priority_queue<long long> pq;
    vector<long long> mn(3 * n);
    for(int i = 3 * n - 1; i >= 0; --i){
        sum += a[i];
        pq.push(a[i]);
        if(pq.size() < n) continue;
        if(pq.size() > n){
            sum -= pq.top();
            pq.pop();
        }
        mn[i] = sum;
    }
    long long ans = -1e18;
    for(int i = n - 1; i < 2 * n; ++i){
        ans = max(ans, mx[i] - mn[i + 1]);
    }
    cout << ans;
}
