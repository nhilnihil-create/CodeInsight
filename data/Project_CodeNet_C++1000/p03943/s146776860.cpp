#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> n(3);
    for(int i=0; i<3; i++) cin >> n.at(i);
    sort(n.begin(), n.end());
    if(n.at(0) + n.at(1) == n.at(2)) puts("Yes");
    else puts("No");
}