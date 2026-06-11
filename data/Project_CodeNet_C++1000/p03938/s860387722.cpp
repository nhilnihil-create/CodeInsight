#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    int n;
    cin >> n;
    vector<int> arr0(n, 0);
    for(auto& val: arr0)
        cin >> val;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++)
        arr[i] = i;
    sort(arr.begin(), arr.end(), [&](int i, int j) {
        return arr0[i] < arr0[j];
         });
    int upper = 1, lower = -1;
    int pre = arr[0];
    vector<int> a = {arr[0]};
    vector<int> b = {0};
    //  2  3
    //  0 -1
    //  2  1  3
    for(int i = 1; i < n; i++) {
        upper = a.back()+1;
        lower = b.back()-1;
        if (arr[i] > pre) {
            upper = arr[i] - lower;
        } else if (arr[i] < pre) {
            lower = arr[i] - upper;
        }
        a.push_back(upper);
        b.push_back(lower);
        pre = arr[i];
    }
    int ma = *min_element(a.begin(), a.end());
    int mb = *min_element(b.begin(), b.end());
    for(int i = 0; i < n; i++)
        cout << a[i]-(ma-1) << " ";
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << b[i]-(mb-1) << " ";
    cout << endl;
    return 0;
}


