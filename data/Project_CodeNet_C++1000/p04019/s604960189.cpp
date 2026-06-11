//Wanna go back home

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end()
#define pb push_back
const int inf = 2147483647;

int main (){
    string s;cin>>s;
    int flag = 0;
    if(s.find("N")==string::npos)flag+=10;
    if(s.find("S")==string::npos)flag-=10;
    if(s.find("W")==string::npos)flag++;
    if(s.find("E")==string::npos)flag--;
    cout << (flag==0 ? "Yes" : "No") << endl;
    return 0;
}