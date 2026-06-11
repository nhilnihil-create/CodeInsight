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

    int a,b;
    cin>>a>>b;
    int x=a+b;
    if(a%3==0 || b%3==0 || x%3==0)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}
