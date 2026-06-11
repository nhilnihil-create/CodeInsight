#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
 
using namespace std;
 
#define PB push_back
#define MP make_pairA
#define REP(i,n) for(int i=0;i<(n);i++)
int main()
{
    string s;
    cin>>s;
    string y="YAKI";
    bool f=true;
    REP(i,y.size())if(y[i]!=s[i])f=false;
    if(f)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
