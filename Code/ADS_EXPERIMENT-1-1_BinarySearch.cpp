#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int binarysearch(int arr[], int n, int key){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int main(){

    cout<<"\nExperiment-1.1 (Ashish Kumar, 23MAI10008)"<<endl<<endl;
    cout<<"Performing Binary Search ..."<<endl;

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
    
    // Binary Search
    int index= binarysearch(arr,n,key);

    if(index == -1){
        cout<<"Element not found!"<<endl;
    }
    else{
        cout<<"Element found at index "<<index<<endl;
    }

}