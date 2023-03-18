#include<bits/stdc++.h>
using namespace std::chrono;
using namespace std;
double a[1000100];
int findpos(double a[],int l,int r)
{

    double need=a[l];
    int cnt=0;
    for(int i=l+1; i<=r; i++)
    {
        if(a[i]<=need)
        {
            cnt++;
        }
    }
    int pos=l+cnt;
    swap(a[l],a[pos]);
    int i=l,j=r;
    while(i<pos&&j>pos)
    {
        while(a[i]<=need)
        {
            i++;
        }
        while(a[j]>need)
        {
            j--;
        }
        if(i<pos&&j>pos)
        {
            swap(a[i++],a[j--]);
        }
    }
    return pos;
}
void quicksort(double a[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int pos=findpos(a,l,r);
    quicksort(a,l,pos-1);
    quicksort(a,pos+1,r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("test.inp","r",stdin);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    auto start = high_resolution_clock::now();
    quicksort(a,1,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<duration.count();
}

