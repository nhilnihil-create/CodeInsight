#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> vec;
    for (int i = 0; i < 3; i++)
    {
        int x; cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    if(vec[2] == vec[0]+vec[1]) puts("Yes");
    else puts("No");
    return 0;
}