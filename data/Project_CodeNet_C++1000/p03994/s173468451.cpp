#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int k;
    cin >> s >> k;
    for(int i=0;i<s.size();i++){
        if(i!=s.size()-1){
            if(s[i]=='a') cout << 'a';
            else{
                if(26-(s[i]-'a')<=k){
                    cout << 'a';
                    k -= 26-(s[i]-'a');
                }
                else cout << s[i];
            }
        }
        else cout << char((k%26+(s[i]-'a'))%26+'a');
    }
    cout << endl;
}