#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[105];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a,a+n);

    int Min = 0x7fffffff;
    for(int i = a[0]-1; i <= a[n-1] + 1; ++i) {
        int ans = 0;
        for(int j = 0; j < n; ++j)
            ans += pow(i-a[j],2);
        if(ans < Min) Min = ans;
    }
    cout << Min << '\n';
return 0;
}