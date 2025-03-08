#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int* readInputFromFile(int size) {
    ifstream file("input.txt");

    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        if (!(file >> arr[i])) {
            cerr << "Error: Not enough data in the file!" << endl;
            delete[] arr; 
            exit(1); 
        }
    }

    file.close();
    return arr;
}

double timeInsertionSort(int arr[], int n) {
    clock_t start = clock();
    insertionSort(arr, n);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int size;
    char continueSorting = 'y';

    while (continueSorting == 'y' || continueSorting == 'Y') {
        cout << "Enter the number of elements you want to sort: ";
        cin >> size;

        int* arr = readInputFromFile(size);

        double elapsedTime = timeInsertionSort(arr, size);

        cout << "Time taken for insertion sort with " << size << " elements: "
             << elapsedTime << " seconds." << endl;

        delete[] arr;

        cout << "Do you want to sort another array? (y/n): ";
        cin >> continueSorting;
    }

    cout << "Thank you for using the Insertion Sort program!" << endl;
    return 0;
}
