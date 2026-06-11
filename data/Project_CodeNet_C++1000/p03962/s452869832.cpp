//In the name of 'ALLAH'//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x , y , z ;
    cin >> x >> y >> z ;
    set<int> s;
    for(int i=0;i<3;i++)
    {
        s.insert(x);
        s.insert(y);
        s.insert(z);

    }
    cout<<s.size()<<endl;
}
