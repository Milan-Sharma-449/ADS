#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void selectionSort(int arr[], int n){

    cout<<endl;
    for(int i=0; i<n-1; i++){
        int minindex=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        swap(arr[i],arr[minindex]);

        cout<<"Round "<<i+1<<": ";
        printArray(arr,n);
        cout<<endl;
    }
    cout<<endl;

}

int main(){

    cout<<"\nExperiment-1.3 (Ashish Kumar, 23MAI10008)"<<endl<<endl;
    cout<<"Performing Selection Sort ..."<<endl;

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

    // Selection Sort Function
    selectionSort(arr,n);

    cout<<"Sorted Array is: ";
    printArray(arr,n);

}