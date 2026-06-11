#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]==s[i+1]){
            s.erase(s.begin()+i);
                i--;
        }
    }
    cout<<(s.length()-1)<<endl;
    return 0;
}
