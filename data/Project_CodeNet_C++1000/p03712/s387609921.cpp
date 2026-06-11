#include <bits/stdc++.h>
using namespace std;
 
int main() {
int H;
int W;

cin>>H>>W;
vector<string> vec(H);
for(int h=0;h<H;h++)
 {
   cin>>vec.at(h);
 }
 for(int l=0;l<W+2;l++)
 {cout<<"#";
 if(l==W+1)cout<<endl;
 }
for(int j=0;j<H;j++)
 {
   cout<<"#"<<vec.at(j)<<"#"<<endl;
 }
 for(int m=0;m<W+2;m++)
 {cout<<"#";
 if(m==W+1)cout<<endl;
 }
}