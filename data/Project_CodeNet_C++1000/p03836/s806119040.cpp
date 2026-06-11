#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;


  




int main(void)
{
    int sx,sy,tx,ty,dx,dy;
    string path[4],ans;

    cin>>sx>>sy>>tx>>ty;

    dx=tx-sx;
    dy=ty-sy;

  
    path[0]="L";
    rep(i,dy+1){
        path[0] += "U";
    }
    rep(i,dx+1){
        path[0]+="R";
    }
    path[0]+="D";

    path[1]="R";
    rep(i,dy+1){
        path[1]+="D";
    }
    rep(i,dx+1){
        path[1]+="L";
    }
    path[1]+="U";

    path[2]="";
    rep(i,dx){
        path[2]+="R";
    }
    rep(i,dy){
        path[2]+="U";
    }

    path[3]="";
    rep(i,dx){
        path[3]+="L";
    }
    rep(i,dy){
        path[3]+="D";
    }

    cout<<path[0]<<path[1]<<path[2]<<path[3]<<endl;


 
 
	return 0;
}
