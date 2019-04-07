#include<iostream>
using namespace std;
int main()
{
  int n,i,j,k,t,c;
  float avwt=0.0,avtat=0.0;
  cout<<"|||||||||||FIRST COME FIRST SERVE|||||||||||"<<endl<<endl;
  cout<<"Enter no. of Process\n";
  cin>>n;
  int at[n],bt[n],ct[n],wt[n],tat[n],nat[n];

  cout<<"Enter arrival Times\n";
  for(i=0;i<n;i++){
      cout<<"Process "<<i+1<<": ";
      cin>>at[i];}

  cout<<"Now enter Burst Time\n";
  for(i=0;i<n;i++){
      cout<<"Process "<<i+1<<": ";
      cin>>bt[i];}

  for(i=1;i<n;i++)
  {
      j=i-1;
      k=at[i];

      while((j>=0)&&(k<at[j]))
      {
          at[j+1]=at[j];
          at[j]=k;
          t=bt[j+1];
          bt[j+1]=bt[j];
          bt[j]=t;
          j--;
      }
  }
 c=at[0];

 for(i=0;i<n;i++)
 {
    ct[i]=c+bt[i];
    nat[i]=c;
    c=ct[i];
 }

 for(i=0;i<n;i++)
   wt[i]=nat[i]-at[i];  
 

 for(i=0;i<n;i++)
     tat[i]=ct[i]-at[i];

 cout<<"Average waiting time: ";
 for(i=0;i<n;i++)
     avwt=avwt+wt[i];

 cout<<(avwt/n)<<endl;

 cout<<"Average Turn Around Time: ";
 for(i=0;i<n;i++)
    avtat=avtat+tat[i];

 cout<<(avtat/n)<<endl;

 cout<<endl;

 return 0;

}
