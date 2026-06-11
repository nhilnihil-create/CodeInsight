#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	string tmp;
    int h,w;
    cin >> h >> w;
    vector<string> a;
    REP(i,h){
        cin >> tmp;
        a.push_back(tmp);
    }
	int cou[26]={};
    REP(i,h) REP(j,w) cou[a[i][j]-'a']++;
    int mo[4]={};
    REP(i,26) mo[cou[i]%4]++;
    bool ch = true;
    if(h%2==1&&w%2==1){
        if(mo[1]==1&&mo[3]==0){
            mo[1]--;
            mo[0]++;
        }
        else if(mo[1]==0&&mo[3]==1){
            mo[3]--;
            mo[2]++;
        }
        else ch = false;
        if(mo[2]>(h-1)/2+(w-1)/2) ch = false;
    }
    else if(h%2==1){
        if(mo[1]!=0||mo[3]!=0) ch = false;
        if(mo[2]>w/2) ch = false;
    }
    else if(w%2==1){
        if(mo[1]!=0||mo[3]!=0) ch = false;
        if(mo[2]>h/2) ch = false;
    }
    else{
        if(mo[1]!=0||mo[3]!=0||mo[2]!=0) ch = false;
    }
	if(ch)cout << "Yes" << endl;
	else cout <<"No"<<endl;
}
