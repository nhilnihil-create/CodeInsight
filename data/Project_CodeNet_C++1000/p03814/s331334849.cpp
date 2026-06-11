#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a,b=0,i=1,j,saidai=0;
    string s;
    cin >> s;
    a=s.size();
    for(i=0;i<a;i++)
    {
        if(s.at(i)!='A')
        {
            continue;
        }
        for(j=0;saidai<a-j-1;j++)
        {
            if(s.at(i)=='A' && s.at(a-j-1)=='Z')
            {
                cout << a-j-i << endl;
                return 0;
            }
        }
    }
    return 0;

}
