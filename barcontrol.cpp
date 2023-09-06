#include <vector>
#include "barcontrol.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;

void printSearch(int size, int line, int delay, char side){
    cout << "\033[" << (line + 3) << "H\033[500D";

    if(side == 'R'){
        cout << "\033[500C"; cout.flush();
    }

    for(int i = 0; i < size; i++){
        sleep_for(chrono::milliseconds(delay));

        if(side == 'R'){
            cout << "\033[2D"; cout.flush();
            cout << "\033[48;2;255;255;0m \033[0m"; cout.flush();
        } 
        else{
            cout << "\033[48;2;255;255;0m \033[0m"; cout.flush();
        }   
    }
}

void printBar(int size, int line, int delay, char side){
    cout << "\033[" << (line + 3) << "H\033[500D";

    if(side == 'R'){
        cout << "\033[500C"; cout.flush();
    }

    for(int i = 0; i < size; i++){
        sleep_for(chrono::milliseconds(delay));

        if(side == 'R'){
            cout << "\033[2D"; cout.flush();
        }      
        if(line % 2 == 0){
            cout << "\033[48;2;75;34;150m \033[0m"; cout.flush();
        }
        else{
            cout << "\033[48;2;200;50;40m \033[0m"; cout.flush();
        }
    }
}

void deleteBar(int size, int line, int delay, char side){
    cout << "\033[" << (line + 3) << "H";
    if(side == 'R'){
        cout << "\033[500C\033[" << (size + 1) << "D";
    }
    else {
        cout << "\033[500D\033[" << (size + 1) << "C";
    }

    for(int i = 0; i < size; i++){
        sleep_for(chrono::milliseconds(delay));
        if(side == 'R'){
            cout << " "; cout.flush();
        }
        else {
            cout << "\033[2D "; cout.flush();
        }
    }
}
