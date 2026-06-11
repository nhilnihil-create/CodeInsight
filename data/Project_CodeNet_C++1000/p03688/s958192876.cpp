#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100005];
    int b[100005]{0};
    int l = n, r = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[a[i]]++;
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    if(r - l > 1){
        cout << "No" << endl;
    }
    else if(l == r){
        if(l <= n / 2 || l == n - 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        if(r >= b[l] + 1 && r <= b[l] + b[r] / 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
