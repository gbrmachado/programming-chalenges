/* Solved by Goma
 * 28/12/2015
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int num;
    int *array, *hash;
    while(cin >> num) {
        array = new int[num];
        hash = new int[num];
        bool printJolly = true;
        for (int i=0; i< num; i++) {//read the values
            cin >> array[i];
            hash[i] = 0;
        }
        for (int i=1; i<num; i++) {
            int aux = abs(array[i] - array[i-1]) ;
            if (aux > 0 && aux < num && hash[aux] != 1) 
                hash[aux]++;
            else {
                cout << "Not jolly"<<endl;
                printJolly = false;
                break;
            }
        }
        if (printJolly)  cout << "Jolly"<<endl;
        delete(array); delete(hash);
    }
    return 0;
}
