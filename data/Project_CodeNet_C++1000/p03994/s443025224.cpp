#include <iostream>
using namespace std;

int main() {
    int len, k;
    string s;
    cin >> s >> k;
    len = s.length();
    for(int i=0;i<len;i++){
        if(s[i] == 'a') continue;
        int dst = 1 + 'z' - s[i];
        if(dst <= k){
            k -= dst;
            s[i] = 'a';
        }
    }
    s[len-1] += k%26;
    if(s[len] > 'z') s[len-1] -= 26;
    cout << s << endl;
	return 0;
}