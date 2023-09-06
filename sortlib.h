#ifndef SORT_LIB_H
#define SORT_LIB_H

#include <vector>

using namespace std;

void merge(vector<int>* numbers, int start, int end, int mid, int delay);
void mergeSort(vector<int>* numbers, int start, int end, int delay);
void quickSort(vector<int>* numbers, int start, int end, int delay);
int binarySearch(vector<int>* numbers, int pivot, int start, int end, int delay, char side);
int sequencialSearch(vector<int>* numbers, int toFind, int delay, char side);

#endif
