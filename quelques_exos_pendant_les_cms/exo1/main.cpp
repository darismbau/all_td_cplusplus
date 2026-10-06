//
// Created by dariu on 06/10/2026.
//

#include <iostream>
using namespace std;

void dump(int* buff, unsigned int buffSize);

int main()
{
    cout << "---buff---";
    int buff[]={12,25,8,6,586};
    dump(buff,5);

    cout << endl << "---buff2---";
    int *buff2 = new int[2];
    buff2[0] = 45;
    buff2[1] = 100;
    dump(buff2,2);

    delete[] buff2;
}

void dump(int* buff, unsigned int buffSize)
{
    for(unsigned int i=0; i<buffSize; ++i)
        cout << endl << buff[i] << endl;
}