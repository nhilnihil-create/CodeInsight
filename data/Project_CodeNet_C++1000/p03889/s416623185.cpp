#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
string st;
int f[1000+5][1000+5],l;
int main()
{
    f[int('b')][int('d')]=1;f[int('d')][int('b')]=1;
    f[int('p')][int('q')]=1;f[int('q')][int('p')]=1;
    cin>>st;
    st=" "+st;l=st.size();l--;
    for (int i=1;i<=l;i++)
      if (f[int(st[i])][int(st[l-i+1])]==0) {cout<<"No";return 0; } 
    cout<<"Yes";
	return 0;
}
