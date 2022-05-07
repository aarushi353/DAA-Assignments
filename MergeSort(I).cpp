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

void MergeSort(int arr[], int size){
    int curr_size;
    int left_start;

    for(curr_size=1;curr_size<=size-1;curr_size = 2*curr_size){
        for(left_start=0;left_start<size-1;left_start += 2*curr_size){
            int mid = min(left_start + curr_size - 1, size-1);
            int right_end = min(left_start+2*curr_size-1, size-1);

            merge(arr, left_start, mid, right_end);
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
    MergeSort(arr, n);

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

}