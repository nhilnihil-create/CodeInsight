#include <iostream>
#include <string>
using namespace std;

int main()
{
    string t = "CODEFESTIVAL2016";
    string S;
    cin >> S;

    int count = 0;
    for(int i = 0; i < t.size(); i++) {
        if(S[i] != t[i]) {
            count += 1;
        }
    }
    cout << count << endl;

    return 0;
}