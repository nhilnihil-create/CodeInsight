#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool a[26];
size_t i;
string s;

int main()
{
    cin >> s;
    for (i = 0; i < s.size(); i++) a[s[i]-'a'] = 1;
    for (i = 0; i < 26; i++) {
        if (a[i] == 0) {
            printf("%c\n", 'a'+i);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}