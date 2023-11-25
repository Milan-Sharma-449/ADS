#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void shellSort(int arr[], int n) {

    // Start with a big gap, then reduce the gap by half
    for( int gap=n/2; gap>0; gap=gap/2) {

        //Sort elements in each sublist
        for(int i= gap; i<n; i++) {
            int temp=arr[i];
            int j;

            //Swap elements in sublist if not in order
            for(j=i; j>=gap && arr[j-gap]>temp; j=j-gap) {
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
        cout<<"Gap "<<gap<<" Sorting :";
        printArray(arr,n);
    }

}


int main() {
    
    cout<<"\nExperiment-2.2 (Ashish Kumar, 23MAI10008)"<<endl<<endl;
    cout<<"Performing Shell Sort ..."<<endl;

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

    // Shell Sort Function
    shellSort(arr,n);

    cout<<"\nSorted Array is: ";
    printArray(arr,n);
    cout<<endl;

    return 0;
}
