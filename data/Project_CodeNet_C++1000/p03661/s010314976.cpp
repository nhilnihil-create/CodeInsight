#include <iostream>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

int abs(int a) {return (a < 0) ? -a : a;}

int main(){
    int N; cin >> N; int a[N];
    long long s[N], t[N], x=0, y=0;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++)
        s[N-i-1] = (x+=a[i]), t[i] = (y+=a[N-i-1]);

    long long MIN = LONG_MAX;
    for (int i = 1; i < N; i++)
        MIN = min(MIN, abs(t[i-1]-s[i]));

    cout << MIN << endl;

    return 0;
}
