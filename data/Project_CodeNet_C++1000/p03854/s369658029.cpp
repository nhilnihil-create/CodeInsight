#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
string s;
int main(void){
    cin>>s;
    int i=s.size()-1;
    while(i>=0){
        if(i>=4&&s[i]=='m'&&s[i-1]=='a'&&s[i-2]=='e'&&s[i-3]=='r'&&s[i-4]=='d'){
            i=i-5;
        }else if(i>=6&&s[i]=='r'&&s[i-1]=='e'&&s[i-2]=='m'&&s[i-3]=='a'&&s[i-4]=='e'&&s[i-5]=='r'&&s[i-6]=='d'){
            i=i-7;
        }else if(i>=4&&s[i]=='e'&&s[i-1]=='s'&&s[i-2]=='a'&&s[i-3]=='r'&&s[i-4]=='e'){
            i=i-5;
        }else if(i>=5&&s[i]=='r'&&s[i-1]=='e'&&s[i-2]=='s'&&s[i-3]=='a'&&s[i-4]=='r'&&s[i-5]=='e'){
            i=i-6;
        }else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

}

