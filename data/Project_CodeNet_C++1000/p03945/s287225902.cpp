#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin >> s;
    char m, n;
    int count=0;
    m = s[0];
    while (n != m){
        n = m;
        for (int i=0; i<s.length(); i++){
            if (s[i] != m){
                m = s[i];
                s = s.substr(i);
                count++;
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}