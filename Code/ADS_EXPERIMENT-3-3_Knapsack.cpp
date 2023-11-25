#include <iostream>
#include <algorithm>
using namespace std;

// Structure to represent an item
struct Item
{
    int value, weight;
};

// Function to compare two items
bool compare(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

// Function to solve the knapsack problem
double fractionalKnapsack(Item items[], int n, int W)
{
    // Sort the items by value/weight ratio
    sort(items, items + n, compare);

    // Initialize the total value
    double totalValue = 0.0;

    // Iterate over the items
    for (int i = 0; i < n; i++)
    {
        // If the weight of the current item is less than the knapsack capacity
        if (items[i].weight <= W)
        {
            // Add the whole item to the knapsack
            totalValue += items[i].value;
            W -= items[i].weight;
        }
        else
        {
            // Add a fraction of the item to the knapsack
            double fraction = (double)W / (double)items[i].weight;
            totalValue += fraction * items[i].value;
            W = 0;
            break;
        }
    }

    // Return the total value
    return totalValue;
}

// Main function
int main()
{
    // Get the number of items and the knapsack capacity
    cout << "Name: Ashish Kumar \nUID: 23MAI10008\n";
    int n, W;
    cout<<"Enter no of items: ";
    cin >> n;
    cout<<"Enter total weight: ";
    cin >> W;

    // Create an array of items
    Item items[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter item"<<i+1<< " (Profit,Weight): ";
        cin >> items[i].value >> items[i].weight;
    }

    // Solve the knapsack problem
    double totalValue = fractionalKnapsack(items, n, W);

    // Print the total value
    cout<<"Total Profit: "; 
    cout << totalValue << endl;

    return 0;
}