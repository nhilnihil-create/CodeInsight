#include <bits/stdc++.h>
using namespace std;
string w;
long long a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,ww,x,y,z;
int main(){
   cin>>w;
   sort(w.begin(),w.end());
   for(int i=0;i<w.size();i++){
    if(w[i]=='a')a++;
    if(w[i]=='b')b++;
    if(w[i]=='c')c++;
    if(w[i]=='d')d++;
    if(w[i]=='e')e++;
    if(w[i]=='f')f++;
    if(w[i]=='g')g++;
    if(w[i]=='h')h++;
    if(w[i]=='i')i++;
    if(w[i]=='j')j++;
    if(w[i]=='k')k++;
    if(w[i]=='l')l++;
    if(w[i]=='m')m++;
    if(w[i]=='n')n++;
    if(w[i]=='o')o++;
    if(w[i]=='p')p++;
    if(w[i]=='q')q++;
    if(w[i]=='r')r++;
    if(w[i]=='s')s++;
    if(w[i]=='t')t++;
    if(w[i]=='u')u++;
    if(w[i]=='w')ww++;
    if(w[i]=='x')x++;
    if(w[i]=='v')v++;
    if(w[i]=='y')y++;
    if(w[i]=='z')z++;

   }
   if(a%2==0&&b%2==0&&c%2==0&&d%2==0&&e%2==0&&f%2==0&&g%2==0&&h%2==0&&i%2==0&&j%2==0&&
      t%2==0&&s%2==0&&r%2==0&&q%2==0&&p%2==0&&o%2==0&&n%2==0&&m%2==0&&l%2==0&&k%2==0&&
      u%2==0&&v%2==0&&ww%2==0&&x%2==0&&y%2==0&&z%2==0)cout<<"Yes";
        else cout<<"No";


return 0;}


