#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n, m;
    cin>> n >>m;

    long int input1,input2;

    map<long int,int>mp;
    bool x = false;
    vector<long int>check;
    for(long int i = 1; i <= m; i++)
    {
        cin>> input1 >> input2;
        if(!x)
        {

        if((input1 == 1)&&(input2 == n))
            x = true;

        else
        {
            if(input1 == 1)
                mp.insert(make_pair(input2,1));

            if(input2 == n)
                check.push_back(input1);

        }
        }
    }

    for(long int i = 0; i < check.size(); i++)
    {
        if(mp.find(check[i]) != mp.end())
        {
            x = true;
            break;
        }
    }

    if(x)
        cout<< "POSSIBLE";
    else
        cout<< "IMPOSSIBLE";

        return 0;
}
