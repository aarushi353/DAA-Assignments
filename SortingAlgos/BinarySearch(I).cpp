#include<iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x){
  while(l<=r){
     int mid = l + ((r-l))/2;
     // (r-l) is used for controlling overflow states
     if(arr[mid]==x){
         return mid;
     }
     else if(arr[mid]>x){
         r=mid-1;
     }
     if(arr[mid]<x){
         l=mid+1;
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

// Linear search -> TC = O(n)
// Binary Search -> TC = O(log n), SC = O(1)

// suppose mid = (l + r)/2
// if we calculate the middle index like this means our code is not 100% correct, it contains bugs.
// That is, it fails for larger values of int variables low and high. Specifically, it fails if the sum of low and high is greater than the maximum positive int value(231 – 1 ).
// The sum overflows to a negative value and the value stays negative when divided by 2. 
