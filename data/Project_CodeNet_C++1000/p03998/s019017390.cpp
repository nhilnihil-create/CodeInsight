#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    string sa,sb,sc;cin>>sa>>sb>>sc;
    
    int i=0;
    int j=0;
    int k=0;
    
    string tmp = "a";
    
    while(true){
        
        if(tmp[0]=='a'){
            tmp = sa[i];
            ++i;
        }
        if(tmp[0]=='b'){
            tmp = sb[j];
            ++j;
        }
        if(tmp[0]=='c'){
            tmp = sc[k];
            ++k;
        }
        if(i==sa.size()+1){
            cout<<'A'<<endl;
            return 0;
        }
        if(j==sb.size()+1){
            cout<<'B'<<endl;
            return 0;
        }
        if(k==sc.size()+1){
            cout<<'C'<<endl;
            return 0;
        }
    }
	return 0;
}