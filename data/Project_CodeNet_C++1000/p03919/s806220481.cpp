#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(void){
    int H,W ;
    cin >> H >> W ;
    map<int,char> p ;
    p[1]='A',p[2]='B',p[3]='C',p[4]='D',p[5]='E',p[6]='F',p[7]='G',p[8]='H',p[9]='I',p[10]='J',p[11]='K',p[12]='L',p[13]='M',p[14]='N',p[15]='O',p[16]='P',p[17]='Q',p[18]='R',p[19]='S',p[20]='T',p[21]='U',p[22]='V',p[23]='W',p[24]='X',p[25]='Y',p[26]='Z';
    string s[27][27] ;
    for(int i=1;i<=H;i++){
         for(int j=1;j<=W;j++){
              cin >> s[i][j] ;
         }
    }
     for(int i=1;i<=H;i++){
         for(int j=1;j<=W;j++){
              if(s[i][j]=="snuke") cout << p[j]<< i ;
         }   
         
    }
    
}
