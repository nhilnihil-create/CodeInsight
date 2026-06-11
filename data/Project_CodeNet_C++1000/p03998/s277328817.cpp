#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string a,b,c;
    cin >> a >> b >> c;
    //int lena,lenb,lenc;
    int lena=a.size();
    int lenb=b.size();
    int lenc=c.size();
   // printf("lena=%d,lenb=%d,lenc=%d",lena,lenb,lenc);
    char x='a';
    int counta=0,countb=0,countc=0;
    while(1){
        if (x=='a'){
            x=a[counta];
            counta++;
        }
        else if (x=='b'){
            x=b[countb];
            countb++;
        }
        else{
            x=c[countc];
            countc++;
        }
        //printf("%d %d %d\n",counta-1,countb-1,countc-1);
        if (lena==counta-1||countb-1==lenb||countc-1==lenc){
            break;
        }
    }
    if (counta-1==lena){
        printf("A\n");
    }
    else if (countb-1==lenb){
        printf("B\n");
    }
    else if (countc-1==lenc){
        printf("C\n");
    }
}