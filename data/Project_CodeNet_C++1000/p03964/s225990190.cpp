#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <tuple>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unsigned long long t[n], a[n];
    for(int i=0; i<n; ++i) cin >> t[i] >> a[i];

    unsigned long long t_min = t[0], a_min = a[0];
    unsigned long long idx = 0;
    for(int i=1; i<n; ++i){
        idx = max((t_min-1)/t[i], (a_min-1)/a[i])+1;
        t_min = t[i]*idx;
        a_min = a[i]*idx;
    }
    cout << t_min+a_min << endl;
    return 0;
}