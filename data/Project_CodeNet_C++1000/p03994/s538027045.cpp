    #include <bits/stdc++.h>
    using namespace std;
    #define int long long

    signed main() {
        string s;int k;
        cin>>s>>k;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='a')continue;
            if(('z'-s[i])+1<=k){
                k-=('z'-s[i])+1;
                s[i]='a';
            }
                
        }
        s[s.size()-1]=char('a'+(s[s.size()-1]+k-'a')%('z'-'a'+1));
        cout<<s;
    }
