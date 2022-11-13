#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100000],area,x=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int left=i;
        int right=i;
        while (a[left]>=a[i]) {
        left--;
        }
        while (a[right]>=a[i]) {
        right++;
        }
        area=(right-left-1)*a[i];
        if(area>x)
        {
            x=area;
        }
    }
    cout<<x<<endl;
    return 0;
}