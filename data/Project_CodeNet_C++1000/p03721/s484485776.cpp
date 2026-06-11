#include <iostream>
#include <map>
using namespace std;
int main(){
    long long n, k;
    cin >> n >> k;
    long long a, b, tmp=0;
    map<long long,long long>mp;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        mp[a] += b;
    }
/*
for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        std::cout << "key = " << itr->first           // キーを表示
                << ", val = " << itr->second << "\n";    // 値を表示
    }
*/
    //for(auto p : mp) pair だよ~
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        tmp += itr->second;
        a = itr->first;
        if(tmp>=k) break;
    }
    cout << a << endl;
    return 0;
}