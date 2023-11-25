#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(int arr[], int n){

    cout<<endl;
    for(int i=1; i<n; i++){
        bool swapped=false;
        for(int j=0; j<n-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
        cout<<"Round "<<i<<": ";
        printArray(arr,n);
        cout<<endl;
    }
    cout<<endl;

}

int main(){

    cout<<"\nExperiment-1.2 (Ashish Kumar, 23MAI10008)"<<endl<<endl;
    cout<<"Performing Bubble Sort ..."<<endl;

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

    // Bubble Sort Function
    bubbleSort(arr,n);

    cout<<"Sorted Array is: ";
    printArray(arr,n);

}