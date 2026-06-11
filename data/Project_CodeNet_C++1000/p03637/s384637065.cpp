#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt4 = 0, cnt2 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 4 == 0)
            cnt4++;
        else if (x % 2 == 0)
            cnt2++;
        else
            cnt0++;
    }
    if (cnt4 >= cnt0)
        cout << "Yes" << endl;
    else if (cnt4 == cnt0 - 1)
    {
        if(cnt2==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    else if(cnt0==0&&cnt2>=2)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}