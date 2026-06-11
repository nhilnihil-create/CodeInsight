#include <iostream>
#include <map>
using namespace std;
int main(){
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        if(mp[a] == 0) mp[a]++;
        else mp.erase(a);
    }
    cout << mp.size() << endl;
    return 0;
}