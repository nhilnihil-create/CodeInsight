#include<bits/stdc++.h>
using namespace std;

int main()
{
    string name;
    cin>> name;

    int Count;

    bool x = true;


    for(int i = 0; i < name.size(); i++)
    {
        Count = count(name.begin(),name.end(),name[i]);
        if(Count % 2 != 0)
        {
            x = false;
            break;
        }

    }

    if(!x)
        cout<< "No";

    else
        cout<< "Yes";

    return 0;

}
