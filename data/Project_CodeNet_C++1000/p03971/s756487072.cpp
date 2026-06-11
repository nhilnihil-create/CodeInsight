#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,a,b;
    string s;
    cin>>n>>a>>b>>s;
    int r1=0,r2=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            r1++;
            if(r1<=a+b) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else if(s[i]=='b'){
            r1++;r2++;
            if(r1<=a+b && r2<=b) cout<<"Yes"<<endl;
            else {
                cout<<"No"<<endl;
                r1--;r2--;
            }
        }else{
            cout<<"No"<<endl;
        }
    }
}