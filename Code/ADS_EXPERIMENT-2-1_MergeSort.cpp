#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void merge(int arr[], int s, int e){
    //Create 2 new arrays to copy data
    int mid= s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first=new int[len1];
    int *second=new int[len2];

    // copy data into arrays
    int k=s;
    for(int i=0; i<len1; i++){
        first[i]=arr[k];
        k++;
    }
    for(int i=0; i<len2; i++){
        second[i]=arr[k];
        k++;
    }

    //merge sorted arrays
    int index1=0;
    int index2=0;
    k=s;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[k]=first[index1];
            k++;
            index1++;
        }
        else{
            arr[k]=second[index2];
            k++;
            index2++;
        }
    }
    while(index1<len1){
        arr[k]=first[index1];
        k++;
        index1++;
    }
    while(index2<len2){
        arr[k]=second[index2];
        k++;
        index2++;
    }
    delete []first;
    delete []second;

}

void mergeSort(int arr[], int s, int e){

    // Base Case
    if(s>=e){
        return;
    }
 
    int mid=s+(e-s)/2;
    // left part sort
    mergeSort(arr,s,mid);
    // right part sort
    mergeSort(arr,mid+1,e);
    // merge
    merge(arr,s,e);

}

int main() {
    
    cout<<"\nExperiment-2.1 (Ashish Kumar, 23MAI10008)"<<endl<<endl;
    cout<<"Performing Merge Sort ..."<<endl;

    int n;
    int arr[100];
    cout<<"Enter size of array: ";
    cin>>n;

    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<"\nOriginal Array is: ";
    printArray(arr,n);
    cout<<endl;

    // Merge Sort Function
    mergeSort(arr,0,n-1);

    cout<<"Sorted Array is: ";
    printArray(arr,n);

    return 0;
}
