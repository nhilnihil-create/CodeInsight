#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int i,j,sum=0;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {

            if(s[i]==s[j])
            {
                sum+=1;
            }
        }
    }
    if(sum!=0) cout<<"no\n";
    else if(sum==0) cout<<"yes\n";
    return 0;
}
