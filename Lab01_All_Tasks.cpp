//Task 01: resizeArray
#include <iostream>
using namespace std;

// Returns a new array of size 2*size.
// First half: copy of inArray. Second half: 2 * each element of inArray.
int* resizeArray(int inArray[], const int size) {
    int newSize = 2 * size;
    int* newArr = new int[newSize];

    for (int i = 0; i < size; i++) {
        newArr[i] = inArray[i];           // first half: original values
        newArr[size + i] = 2 * inArray[i]; // second half: doubled values
    }
    return newArr;
}

int main() {
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int* resized = resizeArray(arr, size);

    cout << "\nResized array: ";
    for (int i = 0; i < 2 * size; i++) {
        cout << resized[i];
        if (i < 2 * size - 1) cout << ", ";
    }
    cout << endl;

    delete[] arr;
    delete[] resized;
    return 0;
}

//Task 02: Diagonal Matrix Check

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    // Create a square matrix dynamically
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    // Populate the matrix
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Check: all entries outside the main diagonal must be zero
    bool isDiagonal = true;
    for (int i = 0; i < n && isDiagonal; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && matrix[i][j] != 0) {
                isDiagonal = false;
                break;
            }
        }
    }

    if (isDiagonal)
        cout << "The matrix IS a diagonal matrix.\n";
    else
        cout << "The matrix is NOT a diagonal matrix.\n";

    // Free memory
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

//Task 03: Substring from Left
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[30];

    cout << "Enter a string: ";
    cin.getline(str, 30);

    int count;
    cout << "Enter the count: ";
    cin >> count;

    int len = strlen(str);

    if (count < 0 || count > len) {
        cout << "Error: count is out of range.\n";
        return 0;
    }

    // Print the first 'count' characters
    cout << "Substring: ";
    for (int i = 0; i < count; i++) {
        cout << str[i];
    }
    cout << endl;

    return 0;
}
