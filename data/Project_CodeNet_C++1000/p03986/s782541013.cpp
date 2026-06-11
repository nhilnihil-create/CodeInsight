#include <iostream>
#include <vector>
#include <string>
using namespace std;
const long long MAXN= 1e10000;
string str;
int pos1,pos2;
int main()
{
    pos1=0,pos2=1;
    cin>>str;
    int cnt=0;
    while(pos2<=str.size() && cnt<MAXN )
    {
        while (!(str[pos1] == 'S' && str[pos2] == 'T')) {
            pos1++, pos2++;
            if (pos2 > str.size()) break;
        }
        if (pos2 > str.size()) break;
        str.erase(pos1, 2);
        cnt++;
        if(pos1>0)
            pos1--,pos2--;
    }
    cout<<str.size();
    return 0;
}