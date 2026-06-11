#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int cnt=0;
void shuffle(int a, int b, int c){
    if(a%2||b%2||c%2)return;
    cnt++;
    if(cnt>1000){cnt=-1;return ;}
    int x,y,z;
    x=(b+c)/2;
    y=(a+c)/2;
    z=(a+b)/2;
    shuffle(x,y,z);
}
int main(){
    int a,b,c;cin>>a>>b>>c;
    shuffle(a,b,c);
    cout<<cnt;
}

