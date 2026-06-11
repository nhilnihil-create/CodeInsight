#include <bits/stdc++.h>

using namespace std;




int main(void)
{

    string str,ans="";
    stack<char> sta;
    
    cin>>str;

    for(int i=0;i<str.size();i++){
        if(str[i] == 'B'){
            if(sta.size() >0){
                sta.pop();
            }
        }else{
            sta.push(str[i]);
        }
    }

    while(!sta.empty()){
        ans += sta.top();
        sta.pop();
    }
    reverse(ans.begin(),ans.end());


    cout<<ans<<endl;
	return 0;
}
