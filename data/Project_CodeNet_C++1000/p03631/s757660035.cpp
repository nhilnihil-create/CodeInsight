 #include<bits/stdc++.h>
 using namespace std;
 int main(){
     string s;
     cin>>s;
     int i,l=s.length(),flag=0;
     for(i=0;i<l;i++){
        if(s[i]!=s[l-i-1]){
            flag=1;
            break;
        }
     }
     if(flag==1){
        cout<<"No"<<endl;
     }
     else{
        cout<<"Yes"<<endl;
     }
     return 0;
 }
