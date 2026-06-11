#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;

    for(int i = 0; i < s.length(); i++){
        if(s[i] != 'a' && 26-(s[i]-'a') <= k){
            k -= 26-(s[i]-'a');
            s[i] = 'a';
        }
    }

    if(k > 0){
        k %= 26;
        s[s.length()-1] = (s[s.length()-1]-'a' + k)% 26 + 'a';
    }

    cout << s << endl;
    return 0;
}