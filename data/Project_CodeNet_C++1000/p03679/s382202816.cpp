#include <bits/stdc++.h>
using namespace std;
#define lp(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define ll long long
#define ii pair<string,int>ii;

string IntToStr(int tmp){
    ostringstream out;
    out << tmp;
    return out.str();
}

int main()
{
    int x,a,b;
    cin>>x>>a>>b;
    if(a>=b)cout<<"delicious"<<endl;
    else if((b-a)<=x)cout<<"safe"<<endl;
    else cout<<"dangerous"<<endl;
}
