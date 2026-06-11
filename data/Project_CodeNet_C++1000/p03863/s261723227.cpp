#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int cnt = 0;
    vector<int>vis(30, 0);
    for(int i = 0; i < s.size(); i++){
        if(vis[s[i] - 'a'] == 0){
            vis[s[i] - 'a'] = 1;
            cnt++;
        }
    }
    if(cnt == 2){
        cout << "Second";
        return 0;
    }
    int n = s.size();
    if(s[0] == s[n - 1]){
        if(n % 2 == 1){
            cout << "Second";
        }
        else{
            cout << "First";
        }
        return 0;
    }
    if(n % 2 == 1){
        cout << "First";
    }
    else{
        cout << "Second";
    }
    return 0;
}