#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define MAXN 100000
using namespace std;
int N,a[2*MAXN+5];
bool seq[2*MAXN+5];
int Check(int x)
{

    for(int i=1;i<=2*N-1;i++)
        if(a[i]<=x)
            seq[i]=0;
        else
            seq[i]=1;
 //   for(int i=1 ;i<=2*N-1;i++)
   // cout<<seq[i]<<"  ";
 //   cout<<endl;
    if(seq[N]==seq[N-1]||seq[N]==seq[N+1])
    
        return seq[N];//?????????????
    int l=-1,r=-1;
    int ld,rd;
    for(int i=2;i<=N;i++)
        if(seq[i]==seq[i-1])
            l=seq[i],ld=N-i+1;//?????????????
    for(int i=N;i<2*N-1;i++)
        if(seq[i]==seq[i+1])
        {
            r=seq[i];//?????????????
            rd=i-N+1;
            break;
        }
    
    if((l==0&&r==-1)||(l==-1&&r==0)||(l==0&&r==0))//??2?3
        return 0;
    if((l==1&&r==0&&ld>rd)||(l==0&&r==1&&ld<rd))//??4
        return 0;
    if(l==-1&&r==-1&&seq[1]==0)//??5
        return 0;
    return 1;
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=2*N-1;i++)
        scanf("%d",&a[i]);
    int L=0,R=2*N;

    while(L<R)
    {
 //       cout<<endl<<endl<<L<<"   LLL  RRR   "<<R<<endl<<endl;        
	    int mid=(L+R)/2;
//	    cout<<L<<"   two   "<<R<<" mid  "<<mid<<endl<<endl<<endl; 
        if(Check(mid)==0)//O(n)??
         {
         	R=mid;
 //           cout<<"r   "<<R<<endl;	
		 }   
        else
            {
                L=mid+1;
	//			cout<<"   L"<<L<<endl;	
			}
    }
    printf("%d\n",R);
    return 0;
}