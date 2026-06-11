#include <bits/stdc++.h>
using namespace std;
int main() {
int a;
int cnt=0;cin>>a;
if(a%100/10==9)cnt++;
if(a%10==9)cnt++;if(cnt){cout<<"Yes"<<endl;}else cout<<"No"<<endl;
}