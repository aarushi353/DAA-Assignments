#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll binarysearch(ll a[],ll l ,ll r,ll k)
{
while(l<=r)
{
ll mid =l+(r-l)/2;
if(a[mid]<k)
{
l=mid+1;
}
else if(a[mid]>k)
{
r=mid-1;
}
else
return mid;
}
return -1;
}
int main()
{
int n;
cin>>n;
ll a[n];
for(int i=0;i<n;i++)
{
cin>>a[i];
}
//if(a[1]>a[2])
sort(a,a+n);

int q;
cin>>q;
for(int i=0;i<q;i++)
{
ll k;
cin>>k;
cout<<binarysearch(a,0,n-1,k)+1<<endl;//+1 because rank start from 1 not zero
}

}

