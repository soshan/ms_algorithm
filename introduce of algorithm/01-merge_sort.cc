// 归并排序
#include <iostream>

#include "../../ms_util/ms_print.hpp"

using namespace std;
using namespace ms_print;

void merge(int a[], int beg, int mid, int end) {
	int na = mid - beg + 1;
	int nb = end - mid; 
	int* pa = new int[na];
	int* pb = new int[nb];

	for (int i = 0; i < na; ++i) {
		pa[i] = a[beg+i];
	}
	for (int i = 0; i < nb; ++i) {
		pb[i] = a[i+mid+1];
	}

	int i = 0, j = 0, pos = beg;
	while (i < na && j < nb) {
		if (pa[i] < pb[j]) {
			a[pos++] = pa[i++];
		} else {
			a[pos++] = pb[j++];
		}
	}
	if (i >= na) {
		for (; j < nb; ++j) {
			a[pos++] = pb[j];
		}
	} else if (j >= nb) {
		for (; i < na; ++i) {
			a[pos++] = pa[i];
		}
	}
	delete pa;
	delete pb;
	pa = NULL;
	pb = NULL;
}

void merge_sort(int a[], int p, int q) {
	if (p < q) {
		int r = (q + p) / 2;
		merge_sort(a, p, r);
		merge_sort(a, r + 1, q);
		merge(a, p, r, q);
	}
}

void test() {
	int a[8] = {1, 5, 9, 2, 7, 98, 34, 3};
	merge_sort(a, 0, 7);
	print_array(a, 8);
}

int main() {


	test();

	return 0;
}