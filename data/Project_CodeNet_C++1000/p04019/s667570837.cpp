#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descsort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void)
{
    string str;
    cin>>str;
    bool n=str.find("N")!=string::npos;
    bool w=str.find("W")!=string::npos;
    bool e=str.find("E")!=string::npos;
    bool s=str.find("S")!=string::npos;
    bool can1=(n==s); // N もしくは Sが両方存在するのか
    bool can2=(w==e); // W もしくは Eが両方存在するのか
    if(can1 == true && can2==true){cout<<"Yes"<<endl;}
    else cout<<"No"<<endl;
    return 0;
}