#include <iostream>
#include <map>
using namespace std;
int main(){
    int n, a;
    cin >> n;
    map<int,int>mp;
    for(int i=0; i<n; i++){
        cin >> a;
        mp[a]++;
        mp[a+1]++;
        mp[a-1]++;
    }
    int M = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
             M = max(itr->second,M);
    }
    cout << M << endl;
    return 0;
}