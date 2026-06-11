#include <bits/stdc++.h>
using namespace std;
int a[30]= {0};
int main()

{
    string s;

    int c=0;
    cin>>s;

    int len = s.size();

    for(int i=0; i<len; i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            a[s[i]-'a']++;
        }
    }
    for(int i=0; i<26; i++)
    {
        if(a[i]%2!= 0)
        {
            c++;
            break;
        }
    }
    if(c==0)

        cout << "Yes" <<endl;
    else
        cout << "No"<<endl;

    return 0;
}
