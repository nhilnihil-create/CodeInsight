#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    string s;
    cin>>s;
    vector<int> arr(26);
    int f=1;

    for(int i=0;i<s.size();i++){
        if(arr[s[i]-'a']==1){
            cout<<"no"<<endl;
            f=0;
            break;
        }else{
            arr[s[i]-'a']++;
        }
    }
    if(f) cout<<"yes"<<endl;
}
