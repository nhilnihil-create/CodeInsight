#include <algorithm>
#include <iostream>
using namespace std;
int a[1000006];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = n, j = 1; i; -- i, ++ j)
        if (j + 1 > a[i - 1]){
            int ans = 0;
            for (int k = i - 1; k && a[k] == j; -- k)
                ans ^= 1;
            ans |= (a[i] - j) & 1;
            if (ans == 1)
                cout << "First" << endl;
            else
                cout << "Second" << endl;
            return 0;
        }
}
