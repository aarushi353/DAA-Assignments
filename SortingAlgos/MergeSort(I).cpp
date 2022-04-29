#include<iostream>
using namespace std;

int min(int x, int y) { return (x<y)? x :y; }

void merge(int arr[], int l, int mid, int r){
    int i,j,k;
    int n1,n2;
    n1 = (mid-l+1);
    n2 = (r-mid);
    
    // temporary arrays
    int L[n1],R[n2];

    // copy data to temporary arrays
    for(i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(i=0;i<n2;i++){
        R[i] = arr[mid+1+i];
    }

    i=0;
    j=0;
    k=l;
    while (i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k]=L[i];
            i++;
            k++;
        }
        else{
            arr[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size){
   int curr_size;  // For current size of subarrays to be merged
                   // curr_size varies from 1 to n/2
   int left_start; // For picking starting index of left subarray
                   // to be merged
 
   // Merge subarrays in bottom up manner.  First merge subarrays of
   // size 1 to create sorted subarrays of size 2, then merge subarrays
   // of size 2 to create sorted subarrays of size 4, and so on.
   for (curr_size=1; curr_size<=size-1; curr_size = 2*curr_size)
   {
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<size-1; left_start += 2*curr_size)
       {
           // Find ending point of left subarray. mid+1 is starting
           // point of right
           int mid = min(left_start + curr_size - 1, size-1);
 
           int right_end = min(left_start + 2*curr_size - 1, size-1);
 
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
           merge(arr, left_start, mid, right_end);
       }
   }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
       cin >> arr[i];
    }

    mergeSort(arr, n);
    for(int j=0;j<n;j++){
       cout << arr[j]<<" ";
    }
}

// TC = O(nlogn)
// SC = O(N)