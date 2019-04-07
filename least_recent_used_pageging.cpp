#include<iostream>
using namespace std;
int main()
{
    int n,m,j;
cout<<"||||||||||| LEAST RECENTLY USED PAGEGING METHOD |||||||||||"<<endl<<endl;
    
    cout<<"Enter No. Of Pages:  "<<endl;
    cin>>n;
    cout<<"Enter No. Of Frames: "<<endl;
    cin>>m;
    int a[n],f[m];
    cout<<"Now Enter Pages:  ";
    for(j=0;j<n;j++)
        cin>>a[j];
    cout<<endl;
    cout<<" Note: | -1 Represents a Empty Frame |"<<endl<<endl;
    int ch[m];
    int nf=0,x=-1,l=-1,pd=0,e,p,c,i;

    for(j=0;j<m;j++)
        f[j]=-1;

    for(i=0;i<n;i++)
    {
        c=0;
        for(j=0;j<m;j++)
            ch[j]=-1;

        for(j=0;j<m;j++)
        {
            if(a[i]==f[j]) {
                c=c+1;
                break; }
        }

        if(c==1)
            l=i;

        else if((c==0)&&(nf<m))
        {
            f[nf]=a[i];
            nf=nf+1;
            pd=pd+1;
            l=i;
        }

        else if((c==0)&&(nf>=m))
        {
            x=-1;
            while(l>-1)
            {
                p=0;e=0;
                for(j=0;j<m;j++)
                {
                    if(a[l]==ch[j]){
                        p++;
                        break;}
                }   

                for(j=0;j<m;j++)
                {
                    if(a[l]==f[j])
                        e++;
                }
                    

                    if((p==0)&&(e!=0)){
                        x=x+1;
                        ch[x]=a[l];}
             l=l-1;       
            }   
                
                for(j=0;j<m;j++)
                {
                    if(f[j]==ch[x]){
                        f[j]=a[i];
                        l=i;
                        break;
                    }

                }
           pd=pd+1;
        }
        
        cout<<"Frame:->"<<endl;
        for(j=0;j<m;j++)
            cout<<f[j]<<endl;

        cout<<endl;

     }
        
cout<<"No. Of Page Default:-> "<<pd<<endl;
cout<<"No. Of Page Hit:-> "<<(n-pd)<<endl;

return 0;
}





