#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int i=0,j=s.length()-1;
    int start=0,end=0;
    while(i<s.length()){
        if(s[i]=='A')
            break;
        i++;
    }
    while(j>-1){
        if(s[j]=='Z')
         break;
        j--;
    }
    
    cout << j-i+1;
    return 0;
}