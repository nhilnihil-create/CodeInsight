
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1 ,s2 , s ;
    cin>>s1>>s2;
    vector<char>v;
    long long a;
    long long n1=s1.size() , n2=s2.size();
    a=max(n1,n2);
    for (int i=0 ; i<a ; ++i)
    {
        if (i<n2)
        {
            cout<<s1[i]<<s2[i];
        }
        else
        {
            cout<<s1[i];
        }
    }
    cout<<endl;
}
