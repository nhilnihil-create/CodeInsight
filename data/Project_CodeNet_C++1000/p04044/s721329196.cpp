#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("i.txt","r",stdin);
    string s1;
    int n,l;
    cin>>n>>l;
    vector <string> v;
    vector <string>:: iterator it;
    while(n--){
        cin>>s1;
        v.push_back(s1);
    }
    sort(v.begin(),v.end());
    string s2="";
    for(it=v.begin();it!=v.end();it++){
        s2+=*it;
    }
    cout<<s2<<endl;
    return 0;
}
