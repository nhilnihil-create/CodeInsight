#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>

using namespace std;

int med(int a,int b,int c){
    int A[3]={a,b,c};
    sort(A,A+3);
    return A[1];
}

int main(){
    int N;
    int A[200000];
    cin>>N;
    for(int i=1;i<=2*N-1;i++){
        cin>>A[i];
    }
    int low=1;
    int high=2*N;
    int B[200000];
    while(high-low>1){
        int mid=(low+high)/2;
        for(int i=1;i<=2*N-1;i++){
            if(A[i]>=mid){
                B[i]=1;
            }else{
                B[i]=0;
            }
        }
        //中心から最も近い連続したpartを探す．
        int left=N-1;
        int right=N+1;
        int ret=-1;
        while(left>0){
            if(B[left]==B[left+1]){
                ret=B[left];
                break;
            }
            if(B[right]==B[right-1]){
                ret=B[right];
                break;
            }
            left--; right++;
        }
        if(ret==-1){
            if(N%2==0){
                ret=(1-B[N]);
            }else{
                ret=B[N];
            }
        }
        if(ret==0){
            high=mid;
        }else{
            low=mid;
        }
    }
    cout<<low<<endl;
    return 0;
}
