#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100002];

int rec(int k){
    int l = v[k].size();
    if(l == 0) return 0;
    vector<int> w(l);
    for(int i = 0; i < l; i++){
        w[i] = rec(v[k][i]);
    }
    int res = 1;
    sort(w.begin(), w.end(), greater<int>());
    for(int i = 0; i < l; i++){
        res = max(res, w[i] + i + 1);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int a[100002];
    for(int i = 2; i <= n; i++){
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    cout << rec(1) << endl;
}