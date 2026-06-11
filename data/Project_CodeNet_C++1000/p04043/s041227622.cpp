 #include<iostream>
 using namespace std;

 int main()
 {
     int ara[4],i,f=0,s=0;

     for(i=0;i<3;i++){
        cin>>ara[i];
     }

     for(i=0;i<3;i++){
        if(ara[i]==5){
            f++;
        }
     }
     if(f==2){
        cout<<"YES\n";
     }
     else{
        cout<<"NO\n";
     }

     return 0;
 }
