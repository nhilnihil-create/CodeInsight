
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
#define v vector<ll>
#define st stack<ll>
#define pq  priority_queue <int>
#define q queue<ll>
#define mod 1000000005
using namespace std;
 char ch[1000000];
int main(){
    string s="CODEFESTIVAL2016";
    string str;
    int cnt=0;
    cin>>str;
    for(int i=0;i<16;i++){
    	if(s[i]!=str[i]){
    		cnt++;
    	}
    }
    cout<<cnt<<endl;
    return 0;
   }
