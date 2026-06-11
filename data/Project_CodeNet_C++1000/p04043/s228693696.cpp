    #include<bits/stdc++.h>
    using namespace std;
     
    int main(){
    	int i,j,k,c=0,s=0;
      cin>>i>>j>>k;
      if(i==5){
      	c++;
      }
      if(i==7){
      	s++;
      }
      if(j==5){
      	c++;
      }
      if(j==7){
      	s++;
      }
      if(k==5){
      	c++;
      }
      if(k==7){
      	s++;
      }
      if(c==2&&s==1){
      cout<<"YES";
      }
      else{
      cout<<"NO";
      }
    }