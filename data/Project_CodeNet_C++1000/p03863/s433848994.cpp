#include <iostream>

using namespace std;

bool used[26];    


int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        used[s[i]-'a'] = true;
    }
    int cnt = 0;
    for(int i = 0; i < 26; i++){
        if(used[i]) cnt++;
    }
    if(cnt == 2){
        cout << "Second" << endl;
    }else{
        if(s[0] == s[s.size()-1]){
            if(s.size()%2== 0){
                cout << "First" << endl;
            }else{
                cout << "Second" << endl;
            }
        }else{
            if(s.size()%2== 0){
                cout << "Second" << endl;
            }else{
                cout << "First" << endl;
            }
        }
    }
}