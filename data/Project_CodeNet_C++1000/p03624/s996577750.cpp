#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string S;
    cin >> S;
    
    int a = 0;
    for (char i = 'a'; i <= 'z'; i++) {
        if(S.find(i) > S.size()){
            cout << i << endl;
            return 0;
        }
        a++;
    }
    cout << "None" << endl;
}