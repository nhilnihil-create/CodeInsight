#include<bits/stdc++.h>

using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
int b[1000000];
int c[1000000];
int main(){
int n;
int i,j;
cin>>n;
pair<int,int> a[n+1];
for(i=1;i<=n;i++)
    {
        int e;
        cin>>e;
        a[i].first=e;
        a[i].second=i;

    c[e]=i;
    }
    sort(a+1,a+n+1);
int x=n*n;
int fl=0;
for(i=1;i<=n;i++){

    int z=a[i].first;
    int u=a[i].second;
b[z]=a[i].second;
u--;
    for(j=1;j<z;j++){
            if(u==0)
            break;
        if(b[j])
            continue;
        else
        {
            b[j]=a[i].second;
            u--;
        }


    }
    if(u!=0){
        fl=1;
        break;
    }

}

if(fl)
    cout<<"No"<<endl;
else{
    deque<pair<int,int> > ww;
    for(i=1;i<=x;i++){
        if(b[i])
            {
                if(c[i]&&(c[i]!=n))
                {
                    ww.push_back(mp(c[i],n-c[i]));
                }

                continue;}
        else{

            if(ww.empty())
            {
                fl=1;
                break;
            }
            deque<pair<int,int> >::iterator q=ww.begin();
            pair<int,int> s=(*q);
            b[i]=s.first;
            int d=s.second-1;
            s.second=s.second-1;
            ww.pop_front();
            if(d==0){


            }
            else{


                ww.push_front(s);

            }



        }


    }
    if(fl)
        cout<<"No"<<endl;
    else{

        cout<<"Yes"<<endl;
        for(i=1;i<=x;i++)
            cout<<b[i]<<" ";
        cout<<endl;

    }




}




return 0;
}
