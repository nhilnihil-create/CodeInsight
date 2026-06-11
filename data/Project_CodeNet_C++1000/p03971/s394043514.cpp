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
int main() {
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'&&c1<a+b){
            cout<<"Yes"<<endl;
            c1++;continue;
        }
        if(s[i]=='b'&&c2<b&&c1<a+b){
            c1++,c2++;
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;
    }
}

