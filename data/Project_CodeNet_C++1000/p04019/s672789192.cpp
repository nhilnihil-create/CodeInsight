#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
    int n=0;
    int w=0;
    int ss=0;
    int e=0;
    string s;
    cin >> s;
    int m=s.size();
    rep(i,m){
        if(s.at(i)=='N')n++;
        else if(s.at(i)=='W')w++;
        else if(s.at(i)=='S')ss++;
        else if(s.at(i)=='E')e++;
    }
    if((n>0 && ss==0)||(n==0 && ss>0)){
        cout << "No" << endl;
    }
    else if((w>0 && e==0)||(w==0 && e>0)){
        cout << "No" << endl;
    }
    else cout << "Yes" << endl;
} 