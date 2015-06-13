#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

//Turns a string of characters into an array of ints
//"123"  ->  3 2 1 0 0 0 0 0 0 0 
void str2vect (char* v1, int out[10]) {
    int j=0;
    for (int i = (int) strlen(v1)-1 ; i>=0; i--) {
        out[j++] = v1[i] - '0';
    }
    for (int i=j; i<10; i++) {
        out[i] = 0;
    }
}

// Counts the number of carries in the operation
int numcarry (int v1[10], int v2[10]) {
    int carry = 0;
    int sum = 0;
    for (int i = 0; i<10 ; i++) {
        if ( v1[i] + v2[i] + sum >= 10 ) {
            carry++;
            sum = (v1[i] + v2[i]) % 10;
        }
        else sum = 0;
    }
    return carry;
}

int main() {
    int n1[10], n2[10],  //Array of int to represent the numbers
        v1,v2;           //
    char var1[11], var2[11];
    while (1) {
        cin >> var1 >> var2;
        stringstream(var1) >> v1;
        stringstream(var2) >> v2;

        if (strcmp(var1,"0") == 0 && strcmp(var2, "0") == 0) return 0;
      //  if (v1 == 0 && v2 == 0) return 0;

        str2vect(var1,n1);
        str2vect(var2,n2);
        cout << numcarry (n1,n2)<<endl;
    }
    return 0;
}
        





