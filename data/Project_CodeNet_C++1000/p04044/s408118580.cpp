 #include<iostream>
 #include<string>
 using namespace std;

 int main()
 {
     int N,L,i,j;
     string s[101];
     string a[10001];
     string temp;

     cin>>N>>L;
     for(i=0;i<N;i++){
        cin>>s[i];
     }

     for(i=0;i<N;i++){
        for(j=0;j<N-1-i;j++){
            if(s[j]>s[j+1]){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
     }
     for(i=0;i<N;i++){
        cout<<s[i];
     }
     cout<<endl;

     return 0;
 }
