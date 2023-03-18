#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
double a[1000100];
void heapify(double a[],int n,int i)
{
    int l=2*i;
    int r=2*i+1;
    int pos=i;
    if(l<=n&&a[l]>a[pos])
    {
        pos=l;
    }
    if(r<=n&&a[r]>a[pos])
    {
        pos=r;
    }
    if(pos!=i)
    {
        swap(a[pos],a[i]);
        heapify(a,n,pos);
    }
}
void heapsort(double a[],int n)
{
    for(int i=n;i>=1;i--)
    {
        heapify(a,n,i);
    }
    for(int i=n;i>=1;i--)
    {
        swap(a[1],a[i]);
        heapify(a,i-1,1);
    }
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
    heapsort(a,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<duration.count();
}

