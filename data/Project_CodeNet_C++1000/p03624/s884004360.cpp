#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string S, ans = "None", alp = "abcdefghijklmnopqrstuvwxyz";
    bool found = true;
    cin >> S;
    vector<int> a(26);
    for(char i : S){
        a[i - 'a']++;
    }
    for(int j; j < 26; j++){
        if(a[j] == 0){
            cout << alp[j] << endl;
            found = false;
            break;
        }
    }
    if(found) cout << ans << endl;
}