#include <bits/stdc++.h>

using namespace std;




int main(void)
{
    string w;
    bool ansFlag=true;
    map<char,int> mp;

    cin>>w;

    for(int i=0;i<w.size();i++){
        mp[w[i]]++;
    }

    for(auto i:mp){
        if(i.second %2 != 0){
            ansFlag = false;
        }
    }

    if(ansFlag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

 
	return 0;
}
