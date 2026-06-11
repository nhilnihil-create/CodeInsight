#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int scount=0; //记录s出现次数 
    int n=s.size();
    for(int i=0;i<s.size();i++){
        if(s[i]=='T'&& scount>0){
             //删除一对 
            n-=2; 
            scount--;
            continue;
        }
        if(s[i]=='S'){
                scount++;
        }
    }
    printf("%d\n",n);
}
