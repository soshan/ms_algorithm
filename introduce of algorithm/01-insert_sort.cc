// 插入排序
#include <iostream>

using namespace std;

void insert_sort(int a[], int n) { // O(n^2)
  for (int i = 1; i < n; ++i) {
	int key = a[i];
	int j = i - 1;
	while (j >= 0 && a[j] > key) {
	  a[j+1] = a[j];
	  --j;
	}
	a[j+1] = key;
  }
}

void test() {
  int a[5] = {1, 4, 9, 2, 6};
  insert_sort(a, 5);
  for (int i=0; i<5; ++i) {
	cout << a[i] << " ";
  }
  cout << endl;
}

int main() {

  test();

  return 0;
}