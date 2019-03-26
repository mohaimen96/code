#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char ar[1000];
char str[1000];
int mn,mx,ar_sz=0;


void fun(int idx,int low,int up, int num,int len)
{
    if(idx==len)
    {
        if(low==1 && up==1 && num==1)
        {
            str[idx]='\0';
            cout<<str<<endl;
        }
        return;
    }
    for(int i=0;i<ar_sz;i++)
    {
        str[idx]=ar[i];
        if(ar[i]>='0' && ar[i]<='9')
        {
            fun(idx+1,low,up,1,len);
        }
        else if(ar[i]>='A' && ar[i]<='Z')
        {
            fun(idx+1,low,1,num,len);
        }
        else
        {
            fun(idx+1,1,up,num,len);
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    string sample;
    cin>>sample;
    cin>>mn>>mx;

    for(int i=0;i<sample.size();i++)
    {
        ar[ar_sz]=sample[i];
        ar_sz++;
        if(sample[i]>='A' && sample[i]<='Z')
        {
            ar[ar_sz]=sample[i]-'A'+'a';
            ar_sz++;
        }
        if(sample[i]>='a' && sample[i]<='z')
        {
            ar[ar_sz]=sample[i]-'a'+'A';
            ar_sz++;
        }
    }
    for(int i=mn;i<=mx;i++)
    {
        fun(0,0,0,0,i);
    }
    return 0;
}
