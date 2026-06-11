#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <functional>

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    for(int i=0; i<n; i++) cin >> l[i];

    sort(l.begin(), l.end());

    int ans = 0;

    for(int i=n-1; i>n-1-k; i--){
        ans += l[i];
    }

    cout << ans << endl;

}