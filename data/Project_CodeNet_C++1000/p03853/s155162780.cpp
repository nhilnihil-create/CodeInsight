#include<iostream>
               
                #include<string> 
                using namespace std;
                int main(){
                  int a,b,i,j;
                  cin>>a>>b;
                  char c[a][b];
                 string s; 
                  for(i=0;i<a;i++){
                    cin>>s;
                    for(j=0;j<b;j++)
                      c[i][j]=s[j];
                  }
                  for(i=0;i<a;i++){
                    for(j=0;j<b;j++){
                      cout<<c[i][j];
                    }
                  cout<<endl;
                  for(j=0;j<b;j++){
                      cout<<c[i][j];
                    }
                  cout<<endl;
                }
                  return 0;
                }