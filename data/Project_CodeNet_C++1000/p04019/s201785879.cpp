#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

char s[N];
int main()
{
    scanf("%s", s);

    int len = strlen(s);
    bool fN = false, fS = false, fE = false, fW = false;
    for (int i = 0; i < len; i ++ )
        if(s[i] == 'N') fN = true;
        else if(s[i] == 'S') fS = true;
        else if(s[i] == 'E') fE = true;
        else fW = true;
    if(!fN && !fS) fN = fS = true;
    if(!fE && !fW) fE = fW = true;
    
    if(fN && fS && fE && fW)
        puts("Yes");
    else
        puts("No");
    
    return 0;
}