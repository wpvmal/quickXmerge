# MergeSort vs. QuickSort Program
## The program includes Binary Search vs. Sequential Search comparison as well

## Compilation

```bash
g++ -c barcontrol.cpp -o barcontrol.o
g++ -c sortlib.cpp -o sortlib.o
g++ mergeXquick.cpp barcontrol.o sortlib.o -o mergeXquick
```
## Execution 

-d or --delay option: Allows you to adjust the delay time (default = 10).
-l or --lines option: Allows you to adjust the number of lines (default = 20).

```bash
  ./mergeXquick [-d|--delay <time>] [-l|--lines <lines>]
```
