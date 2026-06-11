#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1000000007;
#define ll long long
#define PI 3.1416
string day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a,b,c;
    while(cin>>a>>b>>c){
        cout<<((a+b+c)-max(a,max(b,c)))<<endl;
    }
    return 0;
}
