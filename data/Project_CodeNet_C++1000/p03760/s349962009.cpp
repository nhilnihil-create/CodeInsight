#include <bits/stdc++.h>


using namespace std;

#define ll long long

char t[100];
int main(){
   string a,b;
   cin >> a >> b;
   int n=a.size();
   int m=b.size();
   int pos;
   for(int i=0,pos=0;i<n;i++,pos+=2) t[pos]=a[i];
   for(int j=0,pos=1;j<m;j++,pos+=2) t[pos]=b[j];
   string ans;
   for(int k=0;k<n+m;k++) {
	   ans+=t[k];
   }
   cout << ans;
   return 0;
}


