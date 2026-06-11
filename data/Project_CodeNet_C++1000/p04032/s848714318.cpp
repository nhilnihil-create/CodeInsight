#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    string s;
    cin >> s;

    int a, b;
    a = b= -2;
    for(int i=0; i<s.length()-1; i++){
        if(s[i] == s[i+1]){
            a = i;
            b = i+1;
        }

        if(s[i] == s[i+2] && i+2<=s.length()-1){
            a = i;
            b = i+2;
        }
    }

    cout << a+1 << " " << b+1 << endl;

    return 0;
}
