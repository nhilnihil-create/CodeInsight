#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1000000007;
#define ll long long
#define PI 3.1416
string day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a;
    while(cin>>a){
        if(a%10==9 || a/10==9)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
