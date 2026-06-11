#include <bits/stdc++.h>
using namespace std;template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
int main(){cout<<fixed<<setprecision(10);int a,b,c;cin>>a>>b>>c;Yes(2*max(a,max(b,c))==a+b+c);}
