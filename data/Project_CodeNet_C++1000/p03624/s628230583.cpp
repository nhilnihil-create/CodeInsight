    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	string s;
      cin>>s;
      vector<int >ind(26,0);
      for(int i=0;i<s.length();i++)ind[s[i]-'a']=1;
    
      int i=0;
      for(i=0;i<26;i++){
      	if(ind[i]==0)break;
      }
      if(i==26)cout<<"None";
      else cout<<(char)(97+i);
    }