#include <bits/stdc++.h>
using namespace std;
#define lp(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define ll long long

string IntToStr(int tmp){
    ostringstream out;
    out << tmp;
    return out.str();
}


int main()
{
    int a[3];
    for(int i=0; i<3; i++)
        cin>>a[i];
    sort(a,a+3);
    cout<<a[0]+a[1]<<endl;
}
