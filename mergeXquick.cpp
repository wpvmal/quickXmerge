#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "barcontrol.h"
#include "sortlib.h"

using namespace std;
using namespace this_thread;

#define SCREEN_CLEANER cout<<"\033[2J\033[3J\033[H\033[?25l"; cout.flush();

void fillVector(vector<int>*, int);
void argsProcess(int, char**, int*, int*);

int main(int argc, char * argv[]){
    SCREEN_CLEANER
    srand(time(0));
    int delay = 10, lines = 20, toFind;
    vector<int> numbers, mergeNumbers, quickNumbers;

    argsProcess(argc, argv, &delay, &lines);
    
    fillVector(&numbers, lines);
    mergeNumbers = numbers;
    quickNumbers = numbers;

    cout << "\033[H\033[500C\033[22D" "Sequencial Search: ";

    cin >> toFind;
    sequencialSearch(&quickNumbers, toFind, delay, 'R');


    getchar();
    cout << "\033[H\033[2K\033[500C\033[25D" "Any key to use quicksort";
    getchar();
    quickSort(&quickNumbers, 0, (numbers.size() - 1), delay);

    cout << "\033[H\033[2K" "Any key to use merge";
    getchar();

    mergeSort(&mergeNumbers, 0, (numbers.size() - 1), delay);
    cout << "\033[H\033[2K" "Binary Search: ";
    cin >> toFind;
    binarySearch(&mergeNumbers, toFind, 0, (numbers.size() - 1), delay, 'L');
    cout << endl << "\033[?25h";

    return 0;
}

void argsProcess(int argc, char* argv[], int* delay, int* lines){
    if(argc < 2){
        return;
    }
    if(argc == 3 || argc == 5){
        for (int i = 0; i < argc; i++){
            string argString1(argv[i]);
            if(argString1 == "-d" || argString1 == "--delay"){
                (*delay) = atoi(argv[i + 1]);
                continue;
            }
            string argString2(argv[i]);
            if(argString2 == "-l" || argString1 == "--lines"){
                (*lines) = atoi(argv[i + 1]);
                continue;
            }
        }
    }   
}

void fillVector(vector<int>* numbers, int lines){

    for(int i = 0; i < lines; i++){
        (*numbers).push_back((rand() % lines + 1));
    }

    for (int i = 0; i < lines; i++){
        printBar((*numbers)[i], i, 0, 'L');
        printBar((*numbers)[i], i, 0, 'R');
    }
}
