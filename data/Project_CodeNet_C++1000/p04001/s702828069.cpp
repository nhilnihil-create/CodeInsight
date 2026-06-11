#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    string str;
    string copy;
    cin >> str;
    copy = str;
    n = str.length() - 1;//+を入れることができる場所の数
    long long  total = 0LL;
    for (int bit = 0; bit < (1 << n); ++bit)
    {
       
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) { 
                S.push_back(i+1);
            }
        }

       
        for (int i = (int)S.size()-1; i>=0; --i) {
            if (i == (int)S.size() - 1)
                total += stoll(str.substr(S[i]));
            else total += stoll(str.substr(S[i], S[i+1]-S[i]));
            if (i == 0) {
                total += stoll(str.erase(S[i]));
                str = copy;
             }
            
               
            
        }
        if ((int)S.size() == 0) total += stoll(str);
    }
    cout << total ;
    
    

}