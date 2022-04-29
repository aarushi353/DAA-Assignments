#include<iostream>
using namespace std;

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

void mergeSort(int arr[], int l, int r){
   if(l<r){
       int mid = (l + r)/2;
       mergeSort(arr, 0, mid);
       mergeSort(arr, mid + 1,  r);
       merge(arr, l, mid, r);
   }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
       cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);
    for(int j=0;j<n;j++){
       cout << arr[j]<<" ";
    }
}

// SC = O(logn)
// TC = O(nlogn)