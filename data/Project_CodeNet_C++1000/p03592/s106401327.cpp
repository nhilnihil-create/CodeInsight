#include <bits/stdc++.h>
using namespace std;
int main(){int A,B,C; cin>>A>>B>>C;for(int i=0;i<=A;i++)for(int j=0;j<=B;j++)if(i*(B-j)+j*(A-i)==C){cout<<"Yes"<<endl; return 0;}cout<<"No"<<endl;}