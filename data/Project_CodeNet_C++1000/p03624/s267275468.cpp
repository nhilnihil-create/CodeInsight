#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;
    cin>>s;
    int j=0;
    char c=97;
    string A;
    sort(s.begin(), s.end());
    while(c>=97 && c<=122){
        bool yes=binary_search(s.begin(), s.end(),c);
        if(yes){c++;continue;}
        else if(c<=122){A.push_back(c);j++;}
        c++;
    }
    //for(auto x:A)cout<<x <<" ";
    int m=A.length();
    if(m==0){
        cout<<"None" <<"\n";
    }
    else {cout<<A[0] <<"\n";}
}


