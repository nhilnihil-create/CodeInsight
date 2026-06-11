#include<bits/stdc++.h>
#include<math.h>
using namespace std;
string s;
int main()
{
    long long int t,n,i,j,a,b,d,e,k=1,m,c=0;
    cin >> s;
    a= pow(2, s.length() - 1);
    reverse(s.begin(), s.end());
    for(i=1; i<=a; i++)
    {
        k = 1;
        for(j=0; j<s.length()-1; j++)
        {
            c+= (s[j] - '0') * k;
            if((i>>j) & 1)
            {
                k=1;
            }
            else
            {
                k*=10;
            }
        }

        c+= (s[s.length() - 1] - '0') * k;
    }

    cout << c<< endl;
    return 0;
}