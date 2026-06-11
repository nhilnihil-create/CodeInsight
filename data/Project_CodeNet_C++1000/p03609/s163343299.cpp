#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1000000007;
#define ll long long
#define PI 3.1416
string day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a,b;
    while(cin>>a>>b){
        if(a<=b)cout<<"0"<<endl;
        else cout<<(a-b)<<endl;
    }
    return 0;
}
