#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;
    cin>>s;
    int x=-1,y=-1;
  	if (s.size()==2){
    	if (s[0]==s[1]){
        	cout<<1<<' '<<2<<endl;
        }else cout<<-1<<' '<<-1<<endl;
    	return 0;
    }
    for (int i=0;i<s.size()-2;i++){
        if (s[i]==s[i+1]||s[i+1]==s[i+2]||s[i+2]==s[i]){
            x=i+1;
            y=i+3;
            break;
        }
    }cout<<x<<' '<<y<<endl;
    return 0;

}
