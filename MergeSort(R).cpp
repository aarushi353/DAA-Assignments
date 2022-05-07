#include<iostream>
using namespace std;

void Merge(int arr[], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1];
    int R[n2];

    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }    
    for(int i=0;i<n2;i++){
        R[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            k++;
            i++;

        }
        else{
            arr[k]=R[j];
            k++;
            j++;
        }
    }

    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r){
    if(r>l){
      int mid = l + (r-l)/2;
      MergeSort(arr, l, mid);
      MergeSort(arr, mid + 1, r);
      Merge(arr, l, mid, r);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    MergeSort(arr, 0, n-1);

}