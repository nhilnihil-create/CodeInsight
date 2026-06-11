#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int x, y;
    cin >> x >> y;
    vector<int> p(15);
    p[1] = p[3] = p[5] = p[7] = p[8] = p[10] = p[12] = 1;
    p[4] = p[6] = p[9] = p[11] = 2;
    p[2] = 3;
    if (p[x]==p[y])
        cout << "Yes" << endl;
    else
     cout << "No" << endl;
    return 0;
}
