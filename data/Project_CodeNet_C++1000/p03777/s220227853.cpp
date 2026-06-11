    #include <iostream>
    using namespace std;
    int main(void){
      string a,b;
      cin>>a>>b;
      
      if(a==b){
          cout<<"H"<<endl;
      }
      
      else if(a=="D"&&b=="H"){
          cout<<"D"<<endl;
      }
      
      else if(a=="H"&&b=="D"){
          cout<<"D"<<endl;
      }
    }