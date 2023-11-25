#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

// Partition the array using the last element as the pivot
int partition(int arr[], int s, int e) {
    
    // Choose the pivot element
    int pivot = arr[e];
    int i = (s - 1);  
  
    for (int j = s; j <= e - 1; j++) {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot) {
            // Increment index of smaller element  
            i++;   
            int t = arr[i];  
            arr[i] = arr[j];  
            arr[j] = t;  
        }  
    }  
    int t = arr[i+1];  
    arr[i+1] = arr[e];  
    arr[e] = t;  
    
    return (i + 1); 

}

void quickSort(int arr[], int s, int e) {

    // Base Case
    if(s>=e){
        return;
    }

    // p is the partitioning index
    int p = partition(arr,s,e);
    // left part sort
    quickSort(arr,s,p-1);
    // right part sort
    quickSort(arr,p+1,e);

}

int main() {
    
    cout<<"\nExperiment-2.1 (Ashish Kumar, 23MAI10008)"<<endl<<endl;
    cout<<"Performing Quick Sort ..."<<endl;

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

    // Quick Sort Function
    quickSort(arr,0,n-1);

    cout<<"Sorted Array is: ";
    printArray(arr,n);

    return 0;
}
