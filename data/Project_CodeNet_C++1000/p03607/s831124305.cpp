#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

long long n, num;

int main(){
    cin >> n;
    map <int, int> mp;

    for(int i = 0; i < n; i++){
        cin >> num;
        if(mp[num]){
            mp.erase(num);
        }
        else mp[num] = 1;
    }
    cout << mp.size() << endl;
}