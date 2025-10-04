#pragma once
#include <vector>
using namespace std;

template <typename T, typename Compare>
void mergeSort(vector<T>& a, Compare cmp) {
    if (a.size() <= 1) return;

    size_t mid = a.size() / 2;
    vector<T> L(a.begin(), a.begin() + mid);
    vector<T> R(a.begin() + mid, a.end());

    mergeSort(L, cmp);
    mergeSort(R, cmp);

    size_t i = 0, j = 0, k = 0;
    while (i < L.size() && j < R.size()) {
        if (cmp(L[i], R[j])) a[k++] = L[i++];
        else                 a[k++] = R[j++];
    }
    while (i < L.size()) a[k++] = L[i++];
    while (j < R.size()) a[k++] = R[j++];
}
