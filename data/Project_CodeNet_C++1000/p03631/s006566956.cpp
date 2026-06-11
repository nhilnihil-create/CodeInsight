#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1000000007;
#define ll long long
#define PI 3.1416
string day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string st;
    while(cin>>st){
        string str=st;
        reverse(st.begin(),st.end());
        if(st==str) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
