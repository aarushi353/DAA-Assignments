#include<iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x){
  if(l<=r){
     int mid = l + (r-l)/2;

     if(arr[mid]==x){
         return mid;
     }
     else if(arr[mid]>x){
         return binarySearch(arr, l, mid-1, x);
     }
     if(arr[mid]<x){
         return binarySearch(arr,mid + 1, r, x);
     }
  }
  return -1;
}

int main(){
      int n;
      cin>>n;
      int arr[n];
      int number;
      cin>>number;
      for(int i=0;i<n;i++){
          cin>>arr[i];
      }

      int x = binarySearch(arr, 0, n-1, number);
      
      if(x==-1){
          cout<<"Number not found";
      }
      else{
          cout<<"Element "<<number<<" is present at index "<<x;
      }
}
// array inputed is sorted
// Linear search -> TC = O(n)
// Binary Search -> TC = O(log n), SC = O(log n)