#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    string out = "";
    cin >> str;

    for(int i=0; str[i] != '\0'; i++){
        switch (str[i])
        {
        case '0':
            out.push_back(str[i]);
            break;
        case '1':
            out.push_back(str[i]);
            break;
        default:
            if(1 <= out.length()){
                out.pop_back();
                break;
            }
        }
    }
    cout << out << endl;
    return 0;
}