#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //good luck kittu!
    string sa, sb, sc;
    cin>>sa>>sb>>sc;
    int a = sa.size(), b = sb.size(), c = sc.size();
    int i = 0, j = 0, k = 0;
    char curr = sa[0]; i++;
    while(1){
        if((curr=='a' && i==a) || (curr=='b'&&j==b) || (curr=='c'&&k==c)) break;
        if(curr=='a'){
            curr = sa[i];
            i++;
        }
        else if(curr=='b'){
            curr = sb[j];
            j++;
        }
        else if(curr=='c'){
            curr = sc[k];
            k++;
        }
    }
    //cout<<curr<<"\n";
    if(curr=='a' && i==a) cout<<"A\n";
    else if(curr=='b' && j==b) cout<<"B\n";
    else if(curr=='c' && k==c) cout<<"C\n";
    return 0;
}