#include <iostream>
using namespace std;
int main()
{
    string s; cin >> s;
    int count=0;
    for(int i=0;i<s.size();i++)
        if(s[i]=='g') count++;
    if(s.size()%2) cout << count-s.size()/2-1 << endl;
    else cout << count-s.size()/2 << endl;
}