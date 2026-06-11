#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG 
int main(){
    string test;
    cin>>test;
    int n=test.size();
    int count=n+8;
    bool judge=true;
    string s="xxxxxxxxx"+test;
    while((count>8)&&(judge==true)){     
        judge=false;
        if(s[count]=='m'){
            if(s[count-1]=='a'&&s[count-2]=='e'&&s[count-3]=='r'&&s[count-4]=='d'){
                count-=5;
                judge=true;
            }
            else continue;
        }
        else if(s[count]=='e'){
            if(s[count-1]=='s'&&s[count-2]=='a'&&s[count-3]=='r'&&s[count-4]=='e'){
                count-=5;
                judge=true;
            }
            else continue;
        }
        else if(s[count]=='r'&&s[count-1]=='e'&&s[count-2]=='m'){
            if(s[count-3]=='a'&&s[count-4]=='e'&&s[count-5]=='r'&&s[count-6]=='d'){
                count-=7;
                judge=true;
            }
            else continue;
        }
        else if(s[count]=='r'&&s[count-1]=='e'&&s[count-2]=='s'){
            if(s[count-3]=='a'&&s[count-4]=='r'&&s[count-5]=='e'){
                count-=6;
                judge=true;
            }
            else continue;
        }
        else continue;
        }

        if(count==8&&judge==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

}