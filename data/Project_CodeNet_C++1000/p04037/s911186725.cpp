#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2e5+11;

ll list[maxn];

int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>list[i];
    }
    sort(list+1,list+1+n,greater<int>());
    
    for(int i=1;i<=n;i++){
        if(i + 1 > list[i+1]){
            int j=0;
            int a,b;
            while(list[i+1+j] ==i ) j++;
            if((j&1) || (list[i] - i)&1){
                printf("First\n");
            }
            else{
                printf("Second\n");
            }
            return 0;

        }
    }


    return 0;
}