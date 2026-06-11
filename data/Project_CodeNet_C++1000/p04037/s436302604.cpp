#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100005];
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = 0;
    sort(a + 1, a + n + 1, greater<int>());
    int f = 0, s = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > a[i + 1]){
            if((i + a[i]) % 2) f = max(f, min(i, a[i]));
            else s = max(s, min(i, a[i]));
        }
    }
    if(f >= s) cout << "First" << endl;
    else cout << "Second" << endl;
}
