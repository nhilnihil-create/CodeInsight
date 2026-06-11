#include<bits/stdc++.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    if(a[0]=='H' && b[0]=='H'){cout<<"H";}
    else if(a[0]=='H' && b[0]=='D'){cout<<"D";}
    else if(a[0]=='D' && b[0]=='H'){cout<<"D";}
    else if(a[0]=='D' && b[0]=='D'){cout<<"H";}

}
