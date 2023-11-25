#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool linearsearch(int arr[], int size, int element){
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return true;
        }
    }
    return false;
}

int main(){

    cout<<"\nExperiment-1.1 (Ashish Kumar, 23MAI10008)"<<endl<<endl;
    cout<<"Performing Linear Search ..."<<endl;

    int n;
    int arr[1000];
    cout<<"Enter size of array: ";
    cin>>n;
    
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter element to find: ";
    cin>>key;

    cout<<"\nArray: ";
    printArray(arr,n);
    
    // Linear Search
    if(linearsearch(arr,n,key)){
        cout<<"Element found!"<<endl;
    }
    else{
        cout<<"Element not found!"<<endl;
    }

}