#include<iostream>
using namespace std;
int main()
{
cout<<"|||||||||||OPTIMAL PAGE REPLACEMENT|||||||||||"<<endl<<endl;

int n,m;

cout<<"Please Enter No.Of Pages:  ";
cin>>n;
cout<<"Now Enter No. Of Frames:  ";
cin>>m;

int a[n];
int f[m];
int ch[m];
int i,j,k,pd=0,fn=0,c,x,lo,z,h;

for(k=0;k<m;k++)
    f[k]=-1;

cout<<"Now Enter Page Numbers:  ";

for(k=0;k<n;k++)
    cin>>a[k];

for(i=0;i<n;i++)
{
  c=0;
  x=-1;
  
  for(j=0;j<m;j++)
      ch[j]=-1;

  for(j=0;j<m;j++)
  {
      if(a[i]==f[j]){
          c=c+1;
          break;
      }

  }
  
  if((c==0)&&(fn<m))
  {
      f[fn]=a[i];
      fn=fn+1;
      pd=pd+1;
  }


  else if((c==0)&&(fn>=m))
  {

      for(k=i+1;k<n;k++)
      {
          h=0;
          for(j=0;j<m;j++)
          {
              if(a[k]==f[j]){
                  h=h+1;
                  break;
              }
          }


          if(h==1)
          {
              for(j=0;j<m;j++)
              {
                  if(a[k]==ch[j]){
                      h=h+1;
                      break;
                  }
              }
          }
          
          if(h==1){
              x=x+1;
              ch[x]=a[k];
          }
            

      }
        
        if(x!=(m-1))
      {
          for(k=0;k<m;k++)
          {
             z=0; 
            for(j=0;j<=x;j++)
            {
                if(f[k]==ch[j]){
                    z=z+1;
                    break;
                }
            }


             if(z==0){
                  lo=f[k];
                  break;}
              
          }

      for(k=0;k<m;k++)
      {
          if(f[k]==lo){
              f[k]=a[i];
              pd=pd+1;}
      }

    }

      else
      {
          for(k=0;k<m;k++)
        {
             if(f[k]==ch[x]){
                 f[k]=a[i];
                 pd=pd+1;}
         }

      }

  }

 cout<<"|Frames|"<<endl; 
for(k=0;k<m;k++)
    cout<<f[k]<<endl;
cout<<"Page_Default->"<<pd<<endl<<endl;
}


cout<<"Total No Of Page Default: "<<pd<<endl;
cout<<"Total No Of page Hit: "<<(n-pd)<<endl;
return 0;
}
