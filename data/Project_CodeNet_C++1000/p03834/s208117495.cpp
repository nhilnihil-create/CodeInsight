#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
using namespace std;

typedef long long ll;
const int MAX=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main(){
    string s;
    while(cin>>s){
        for(int i=0;i<19;i++){
            if(s[i]==',') s[i]=' ';
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
