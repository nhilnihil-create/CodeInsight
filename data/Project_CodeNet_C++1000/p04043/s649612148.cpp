#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> n(3);
    for(int i=0; i<3; i++) cin >> n.at(i);
    sort(n.begin(), n.end());
    if(n[0] == 5 && n[1] == 5 && n[2] == 7) puts("YES");
    else puts("NO");
}