#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

long long anss,anst;
string s;
int main()
{
    cin>>s;
    for (int i=0; i<s.size(); i++){
        if(s[i]=='S') anss++;
        else {
            anst++;
            if(anss) anss--,anst--;
        }
    }
    cout<<anss+anst<<endl;
    return 0;
}

