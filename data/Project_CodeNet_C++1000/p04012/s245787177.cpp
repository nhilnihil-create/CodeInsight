#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ss;
    cin >> ss;
    int n=0,j=0;
    vector <char> str;
    int a[100]={0};
    int i;
    for(i=0;i<ss.size();i++)
    {
        str.push_back(ss[i]);
    }
    sort(str.begin(),str.end());
    for(i=0;i<ss.size();i++)
    {
        if(str[i]==str[i+1])
        {
            n++;
        }
        else
        {
            a[j]=n+1;
            j++;
            n=0;
        }
        
    }
    for(i=0;i<j;i++)
    {
        if(a[i]%2!=0)
        {
            cout << "No\n" ;
            return 0;
        }
    }
    cout << "Yes\n";
}