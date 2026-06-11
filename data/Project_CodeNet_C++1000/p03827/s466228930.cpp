#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0,mx=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='I')
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        mx = max(mx,cnt);
    }
    cout<< mx <<endl;
    return 0;
}
