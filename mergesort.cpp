#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
double a[1000100],a2[1000100];
void merg(double a[],int l,int mid,int r)
{
    for(int i=l;i<=r;i++)
    {
        a2[i]=a[i];
    }
    int i=l,j=mid+1,pos=l;
    while(i<=mid&&j<=r)
    {
        if(a2[i]<=a2[j])
        {
            a[pos]=a2[i];
            pos++;
            i++;
        }
        else
        {
            a[pos]=a2[j];
            pos++;
            j++;
        }
    }
    while(i<=mid)
    {
        a[pos]=a2[i];
        pos++;
        i++;
    }
    while(j<=r)
    {
        a[pos]=a2[j];
        pos++;
        j++;
    }

}
void mergesort(double a[],int l,int r)
{
    //cout<<l<<" "<<r<<"\n";
    if(l>=r)
    {
        return;
    }
    int mid=l+(r-l)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,r);
    merg(a,l,mid,r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("test.inp","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    auto start = high_resolution_clock::now();
    mergesort(a,1,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<duration.count();
}

