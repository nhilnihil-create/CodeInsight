#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    cin>>a;
    vector<int> pos;
    vector<int> vec('z'-'a'+1,0);
    int cnt=0;
    for(int i=a.size()-1;i>=0;i--){
        if(vec[a[i]-'a']==0){
            vec[a[i]-'a']++;
            cnt++;
        }
        if(cnt=='z'-'a'+1){
            fill(vec.begin(),vec.end(),0);
            cnt=0;
            pos.push_back(i);
        }
    }
    reverse(pos.begin(),pos.end());
    pos.push_back(a.size());
    fill(vec.begin(),vec.end(),0);
    int inde=0;
    string res;
    for(int i=0;i<pos.size();i++){
        for(int j=inde;j<pos[i];j++){
            vec[a[j]-'a']++;
        }
        for(char x='a';x<='z';x++){
            if(!vec[x-'a']){
                res+=x;
                while(inde<a.size() && a[inde]!=x) inde++;
                inde++;
                break;
            }
        }
        fill(vec.begin(),vec.end(),0);
    }
    cout<<res<<endl;
    return 0;
}