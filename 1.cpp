#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to read input from a text file (assumes file is always "input.txt")
int* readInputFromFile(int size) {
    ifstream file("input_sorted_descending.txt");

    // Dynamically allocate array based on size
    int* arr = new int[size];

    // Read the specified number of elements from the file
    for (int i = 0; i < size; ++i) {
        if (!(file >> arr[i])) {
            cerr << "Error: Not enough data in the file!" << endl;
            delete[] arr; // Clean up memory
            exit(1); // Exit if there aren't enough elements
        }
    }

    file.close();
    return arr;
}

// Function to measure time taken for insertion sort
double timeInsertionSort(int arr[], int n) {
    clock_t start = clock();
    insertionSort(arr, n);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int size;
    char continueSorting = 'y';

    // Loop until the user decides to stop
    while (continueSorting == 'y' || continueSorting == 'Y') {
        // Ask the user for the size of input data they want to use
        cout << "Enter the number of elements you want to sort: ";
        cin >> size;

        // Dynamically allocate the array based on size and read from "input.txt"
        int* arr = readInputFromFile(size);

        // Measure the time taken to sort the array
        double elapsedTime = timeInsertionSort(arr, size);

        // Output the time taken for this sorting operation
        cout << "Time taken for insertion sort with " << size << " elements: "
             << elapsedTime << " seconds." << endl;

        // Clean up dynamically allocated memory
        delete[] arr;

        // Ask the user if they want to try with another input size
        cout << "Do you want to sort another array? (y/n): ";
        cin >> continueSorting;
    }

    cout << "Thank you for using the Insertion Sort program!" << endl;
    return 0;
}
