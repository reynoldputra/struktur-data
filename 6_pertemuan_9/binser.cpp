#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high) {

    while (low <= high) {
        for (int i = low; i <= high; i++) {
            cout << array[i] << " ";
        }
        cout << endl;

        int mid = low + (high - low) / 2;

        if (array[mid] == x)
        return mid;

        if (array[mid] < x)
        low = mid + 1;

        else
        high = mid - 1;
    }

    return -1;
}

int main(void) {
  int array[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int x = 23;
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
}