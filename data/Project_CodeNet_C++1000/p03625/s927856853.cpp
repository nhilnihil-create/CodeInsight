#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    cin>> n;

    vector<long long int> vec;

    long long int input;

    for(int i=0; i < n; i++)
    {
        cin>> input;
        vec.push_back(input);
    }

    sort(vec.begin(),vec.end());

    reverse(vec.begin(),vec.end());

    long long int high = 0,temp;
    bool x = true;
    bool ans = false;


    for(int i = 0; i < n; i++)
    {
        if(!x)
        {
            if(vec[i] ==vec[i+1])
            {
                cout<< temp*vec[i] << "\n";
                ans = true;
                break;
            }


        }
        else
        {

            if(vec[i] == vec[i+1])
                high++;
            else
            {

                if(high >=3)
                {
                    cout<< vec[i]*vec[i] << "\n";
                    ans = true;
                    break;
                }

                else if(high >= 1)
                {
                    x = false;
                    temp = vec[i];


                }

            }


        }

    }

    if(!ans)
        cout<< 0;


    return 0;



}




