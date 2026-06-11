#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;

    cin>>s;

    int posA=0,posB=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='A'){
               posA=i+1;
               break;
        }
    }
    for(int i=s.size()-1; i>=posA; i--){
        if(s[i]=='Z'){
            posB=i+1;
            break;
        }
    }
    cout<<posB-posA+1<<endl;
}
