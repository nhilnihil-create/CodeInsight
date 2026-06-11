#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<cctype>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    string S;
    cin >> S;
    bool e=0,w=0,s=0,n=0;
    ll i;
    for(i=0;i<S.size();i++){
        if(S[i]=='S')s=1;
        if(S[i]=='W')w=1;
        if(S[i]=='E')e=1;
        if(S[i]=='N')n=1;
    }
    if((s^n)||(e^w))cout <<"No";else cout <<"Yes";
    cout << endl;
    return 0;
}