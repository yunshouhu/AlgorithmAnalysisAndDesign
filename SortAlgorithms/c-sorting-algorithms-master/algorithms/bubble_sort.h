/*

Bubble sort

Worst case performance: O(n^2)
Best case performance: Ω(n)
Average performance: Θ(n^2)
Worst case space complexity: O(1)

*/

void bubble_sort(int arr[], int n) {
  int temp=0;
  int i=0;
  int j=0;

  while (i < n) {
    j = 0;
    while (j < i) {
      if (arr[j] > arr[i]) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
      j++;
    }
    i++;
  }
}
