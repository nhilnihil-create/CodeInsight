#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
typedef long long ll;
int main()
{
    string a,b;
    cin >> a >> b;

    if(a.size()>b.size())
    {
        cout<<"GREATER"<<endl;
    }

    else if(a.size()<b.size())
    {
        cout<< "LESS" <<endl;
    }
    else
    {

        for(int i=0; i<a.size();i++)
        {
            if(a[i]>b[i])
            {
                cout<< "GREATER" <<endl;
                return 0;
            }
            else if(b[i]>a[i])
            {
                cout<<"LESS" << endl;;
                return 0;
            }
        }
        cout<< "EQUAL" << endl;
    }
    return 0;
}