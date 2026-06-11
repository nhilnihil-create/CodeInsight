#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int

using namespace std;

int main()
{
    string r;

    cin >> r;

    int i , p;

    int a[26]={0};

    for(i=0;i<r.size();i++)
    {
        p=r[i];

        if(p>=97 && p<=122)
        {
            p=r[i]-'a';

            a[p]++;
        }



    }

    bool flg=0;

    for(i=0;i<26;i++)
    {
        if(a[i]%2!=0)
        {
            flg=1;

            break;
        }
    }

    if(flg==1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}
