        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;


     signed main(){
         cout << std::fixed << std::setprecision(15);
string a,v;
cin>>a;
int nx[a.size()],p['z'-'a'+1];char ans[a.size()];
fill(p,p+26,a.size());int t=26;bool x[26];fill(x,x+26,false);
for(int i=a.size()-1;i>=0;i--){
for(int j=0;j<26;j++)if(x[j]==false){
     nx[i]=p[j];
     ans[i]=char(j+'a');
     break;
}
if(x[a[i]-'a']==false){
     x[a[i]-'a']=true;
     t--;
}
p[a[i]-'a']=i;
if(t==0){
     t=26;
     fill(x,x+26,false);
}
}
for(int j=0;j<26;j++)if(x[j]==false){
     t=p[j];
     v.push_back(char(j+'a'));
     break;
}
while(t!=a.size()){
     v.push_back(ans[t]);
     t=nx[t];
}
cout<<v<<endl;

     }

 


 






    





      

        
