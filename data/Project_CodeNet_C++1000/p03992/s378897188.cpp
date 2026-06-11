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
    REP(i,4)cout<<s[i];
    cout<<" ";
    REP(i,8)cout<<s[i+4];
    cout<<endl;
}
