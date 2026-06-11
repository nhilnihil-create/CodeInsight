#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

char s[100005];

int main()
{
    cin >> s;
    int l = strlen(s),p;
    for(register int i = 0; i < l; i++)
    {
        p = l - i - 1;
        if(s[i] == 'b' && s[p] != 'd') {cout << "No" << endl;return 0;}
        if(s[i] == 'd' && s[p] != 'b') {cout << "No" << endl;return 0;}
        if(s[i] == 'p' && s[p] != 'q') {cout << "No" << endl;return 0;}
        if(s[i] == 'q' && s[p] != 'p') {cout << "No" << endl;return 0;}
    }
    cout << "Yes" << endl;
    return 0;
}