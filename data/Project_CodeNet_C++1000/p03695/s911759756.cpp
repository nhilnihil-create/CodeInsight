#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
string array1[]={"gray","brown","green","cyan","blue","yellow","orange","red"};
int main()
{
int n,i,num,mini=0,maxi=0,counter=0;
set<int>visited;
scanf("%d",&n);
for(i=0;i<n;++i){
    scanf("%d",&num);
    if(num>=3200){
        counter++;
    }
    else{
        int choice=floor(1.0*num/400.0);
        visited.insert(choice);
    }
}
mini=visited.size();
if(mini==0){
    mini=1;
    maxi=counter;
}
else{
    maxi=mini+counter;
}
printf("%d %d",mini,maxi);


    return 0;
}
