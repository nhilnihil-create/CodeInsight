#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,four=0,two=0,sonota=0;
    bool yatta = false;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a.at(i);
    }
    //sort(a.begin(), a.end());

    //an.at(0) = a.at(0);
    /*for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N;j++)
        {
            if(tta.at(j)==true)
            {
                continue;
            }
            else if((an.at(i-1)*a.at(j))%4==0)
            {
                an.at(i) = a.at(j);
                tta.at(j) = true;
                break;
            }
        }
    }*/
    for (int i = 0; i < N;i++)
    {
        if(a.at(i)%4==0)
        {
            four++;
        }else if(a.at(i)%2==0)
        {
            two++;
        }else
        {
            sonota++;
            //cout << sonota << endl;
        }
    }

    if(sonota<=four+1 && two==0)
    {
        yatta = true;
    }
    else if(sonota<=four && two>=1)
    {
        yatta = true;
    }

    if(yatta==true)
    {
        cout << "Yes" << endl;
    }else
    {
        cout << "No" << endl;
    }
}
