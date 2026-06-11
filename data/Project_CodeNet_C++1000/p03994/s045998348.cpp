#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    long long int K;
    cin >> s;
    cin >> K;

    for(int i=0;i<s.size();i++){
            
        if(i==s.size()-1){
            s[i] = 'a' + (s[i]-'a'+K)%26;
        }else{
            if(s[i]!='a' && 'a'+26-s[i]<=K){
                K -= 'a'+26-s[i];
                s[i] = 'a';
            }
        }
    }

    cout << s << endl;
}