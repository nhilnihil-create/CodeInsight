#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
    string s;
    cin >> s;
    if(s.size()<4)cout << "No" << endl;
    else{
        bool a=true;
        if(s.at(0)!='Y')a=false;
        if(s.at(1)!='A')a=false;
        if(s.at(2)!='K')a=false;
        if(s.at(3)!='I')a=false;
        if(a)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
}
