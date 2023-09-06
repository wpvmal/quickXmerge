#include "sortlib.h"
#include "barcontrol.h"
#include <thread>
#include <chrono>
#include <time.h>
#include <iostream>

using namespace std;
using namespace this_thread;

void merge(vector<int>* numbers, int start, int end, int mid, int delay){
    int lastFromLeft = mid - start + 1;
    int lastFromRight = end - mid;
    vector<int> leftVector, rightVector;

    for(int i = 0; i < lastFromLeft; i++){
        leftVector.push_back((*numbers)[start + i]);
    }
    for(int i = 0; i < lastFromRight; i++){
        rightVector.push_back((*numbers)[mid + i + 1]);
    }

    int i = 0, j = 0, k = start;

    while (i < lastFromLeft && j < lastFromRight){
        if (leftVector[i] <= rightVector[j]){
            int delTemp = (*numbers)[k];
            (*numbers)[k] = leftVector[i];
            deleteBar(delTemp, k, delay, 'L');
            printBar((*numbers)[k], k, delay, 'L');
            i++;
        }
        else {
            int delTemp = (*numbers)[k];
            (*numbers)[k] = rightVector[j];
            deleteBar(delTemp, k, delay, 'L');
            printBar((*numbers)[k], k, delay, 'L');
            j++;
        }
        k++;
    }

    while (i < lastFromLeft){
        int delTemp = (*numbers)[k];
        (*numbers)[k] = leftVector[i];
        deleteBar(delTemp, k, delay, 'L');
        printBar((*numbers)[k], k, delay, 'L');
        i++;
        k++;
    }

    while (j < lastFromRight){
        int delTemp = (*numbers)[k];
        (*numbers)[k] = rightVector[j];
        deleteBar(delTemp, k, delay, 'L');
        printBar((*numbers)[k], k, delay, 'L');
        j++;
        k++;
    }
}

void mergeSort(vector<int>* numbers, int start, int end, int delay){

    if(start < end){
        int mid = (start + end - 1)/2;
        mergeSort(numbers, start, mid, delay);
        mergeSort(numbers, (mid + 1), end, delay);
        merge(numbers, start, end, mid, delay);
    }
}

void quickSort(vector<int>* numbers, int start, int end, int delay){
    int i = start;
    int j = end;
    int aux;
    int mid = (start + end) / 2;
    int pivot = (*numbers)[mid];
    
    while (i <= j){
        while ((*numbers)[i] < pivot){  
            i++;
        }
        while ((*numbers)[j] > pivot){
            j--;
        }
        if (i <= j){
            deleteBar((*numbers)[i], i, delay, 'R');
            deleteBar((*numbers)[j], j, delay, 'R');
            aux = (*numbers)[i];
            (*numbers)[i] = (*numbers)[j];
            (*numbers)[j] = aux;
            printBar((*numbers)[i], i, delay, 'R');
            printBar((*numbers)[j], j, delay, 'R');
            i++;
            j--;
        } 
    }
    
    if (start < j){
        quickSort(numbers, start, j, delay);
    }
    if (i < end){
        quickSort(numbers, i, end, delay);
    }
}

void foundInSearch(vector<int>* numbers, int toFind, char side, int index){

    if(side == 'R'){
        cout << "\033[H\033[" << ((*numbers).size() + 3) << "B";
        if(index != -1){
            cout << "\033[500C\033[23D";
            cout << toFind << " found on line: " << index + 1;
        }
        else {
            cout << "\033[500C\033[15D";
            cout << toFind << " not found.";
        }
    }
    else{
        cout << "\033[H\033[" << ((*numbers).size() + 3) << "B";
        if(index != -1){
            cout << toFind << " found on line: " << index + 1;
        }
        else {
            cout << toFind << " not found.";
        }
    }
}

int binarySearch(vector<int>* numbers, int toFind, int start, int end, int delay, char side){
    int mid = (end + start)/2;

    deleteBar((*numbers)[mid], mid, (delay * 10), side);
    printSearch((*numbers)[mid], mid, (delay * 10), side);
    sleep_for(chrono::milliseconds(delay * 10));
    printBar((*numbers)[mid], mid, 0, side);

    if (toFind == (*numbers)[mid]){
        foundInSearch(numbers, toFind, side, mid);
        return mid;
    }

    if(start >= end){
        foundInSearch(numbers, toFind, side, -1);
        return -1;
    }
    
    if (toFind < (*numbers)[mid]){
        return binarySearch(numbers, toFind, start, mid, delay, side);
    }
    return binarySearch(numbers, toFind, mid + 1, end, delay, side);
}

int sequencialSearch(vector<int>* numbers, int toFind, int delay, char side){

    for(int i = 0; i < (*numbers).size(); i++){
        deleteBar((*numbers)[i], i, (delay * 10), side);
        printSearch((*numbers)[i], i, (delay * 10), side);
        if(toFind == (*numbers)[i]){
            foundInSearch(numbers, toFind, side, i);
            return i;
        }
        printBar((*numbers)[i], i, 0, side);
    }
    foundInSearch(numbers, toFind, side, -1);
    return -1;
    
}