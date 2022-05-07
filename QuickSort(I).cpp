#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high){
    int pivot = arr[high];
       int i = (low-1);
       for(int j=low;j<=high;j++){
          if(arr[j]<pivot){
              i++;
              swap(arr[i], arr[j]);
          }
       }
       swap(arr[i+1], arr[high]);
       return (i+1);
}

void QuickSort(int arr[], int low, int high){
     int stack[high-low+1];
     int top = -1;

     stack[++top] = low;
     stack[++top] = high;

     while(top >= 0){
         high = stack[top--];
         low = stack[top--];

         int p = partition(arr, low, high);

         if((p-1)>low){
             stack[++top] = low;
             stack[++top] = p-1;

         }

         if(p+1<high){
             stack[++top] = p+1;
             stack[++top] = high;
         }
     }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    QuickSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    

}