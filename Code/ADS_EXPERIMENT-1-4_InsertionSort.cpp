#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int arr[], int n){

    cout<<endl;
    for(int i=1; i<n; i++){
        int temp=arr[i];
        int j=i-1;
        for(; j>=0; j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;

        cout<<"Round "<<i<<": ";
        printArray(arr,n);
        cout<<endl;
    }
    cout<<endl;

}

int main(){

    cout<<"\nExperiment-1.4 (Ashish Kumar, 23MAI10008)"<<endl<<endl;
    cout<<"Performing Insertion Sort ..."<<endl;

    int n;
    int arr[100];
    cout<<"Enter size of array: ";
    cin>>n;

    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<"Original Array is: ";
    printArray(arr,n);
    cout<<endl;

    // Insertion Sort Function
    insertionSort(arr,n);

    cout<<"Sorted Array is: ";
    printArray(arr,n);

}