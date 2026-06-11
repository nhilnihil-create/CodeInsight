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
        if(c-b<=0)cout<<"delicious"<<endl;
        else if(c-b<=a)cout<<"safe"<<endl;
        else cout<<"dangerous"<<endl;
    }
    return 0;
}
