#include <iostream>
#include <cstdio>
using namespace std;

char next(char s, long long k){
    char ans;
    if(s + k <= 'z'){
        ans = s + k;
    }
    else{
        long long distance = 'z' - s;
        k -= distance;
        k -= 1;
        ans = 'a' + k;
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    long long k;
    cin >> k;

    for(long long i = 0; i < s.size(); i++){
        if(i == s.size()-1){
            k = k % 26;
            s[i] = next(s[i], k);
        }
        else{
            if(s[i] == 'a'){
                continue;
            }
            long long distance = 'z' - s[i] + 1;
            if(distance > k){
                continue;
            }
            else{
                k -= distance;
                s[i] = 'a';
            }
        }
    }

    cout << s << endl;
    return 0;
}