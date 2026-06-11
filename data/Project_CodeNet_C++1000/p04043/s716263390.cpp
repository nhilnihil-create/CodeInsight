/// @author MUSTAFA MOGHAZY
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a [10];
int main()
{
 int c = 3;
 while(c--){
    int in; cin>>in;
    ++a[in];
 }
 if(a[5]==2 && a[7]==1){
    cout<<"YES";
 }
 else
    cout<<"NO";

}
