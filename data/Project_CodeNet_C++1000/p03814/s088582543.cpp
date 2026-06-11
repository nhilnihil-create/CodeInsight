#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int A, Z;
    int count = s.size();
    for (int i = 0; i < count; i++)
    {
        if(s.at(i) == 'A'){
            A = i;
            break;
        }
    }
    for (int i = 0; i < count; i++)
    {
        if(s.at(count-1-i) == 'Z'){
            Z = count -1 -i;
            break;
        }
    }
    cout << Z - A +1 << endl;
    
    

}
