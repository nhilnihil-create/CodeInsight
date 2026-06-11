#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define endll "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,int>mp;
    string s;
    cin >> s;
    int c=0;
    for(int i=0;i<s.size();i++){
        if(mp.count(s[i])==false){
            mp.insert(make_pair(s[i],1));
        }
        else {
            mp[s[i]]++;
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        

        if(it->second%2==0){

            continue;
        }
        else{
            cout << "No" << endl;
            return 0;
        }

    }
    cout << "Yes" << endl;

    return 0;
}

