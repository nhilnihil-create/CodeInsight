#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    string str;
    cin >> str;
    ll ans = 1;
    ll sum = str.size();

    map<char,int> map;
    for(int i = 0; i < str.size(); i++){
        map[str[i]]++;
    } 
    
    for(int i = 0; i < str.size(); i++){ 
        ans += sum - map[str[i]];
        sum--;
        map[str[i]]--;
    }

    cout << ans << endl;

}

