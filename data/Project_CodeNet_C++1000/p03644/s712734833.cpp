#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mx=0,ans;
    for(int i=0;i<=20;i++)
    {
        if(n< (1<<(i+1)))
            {
                cout << (1<<i) << endl;
                break;
            }
    }
    return 0;
}
