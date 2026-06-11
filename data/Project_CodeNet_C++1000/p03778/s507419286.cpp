#include<bits/stdc++.h>
#include <vector>
#define endl '\n';
using namespace std;

int main()
{   
    int w, a, b; cin >> w >> a >> b;
    int aw = a + w, bw = b + w;
    if (aw >= b && bw >= a) cout << 0;
    else if (b > aw) cout << b - aw;
    else cout << a - bw;
    return 0;
}