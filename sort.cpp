#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
double a[1000100];
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
    sort(a+1,a+n+1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<duration.count();
}


