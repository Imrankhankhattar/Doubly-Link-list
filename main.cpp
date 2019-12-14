#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i,j,x,add,siz=100,lenght=0;
    char A[siz],R[siz];
    cout<<"Enter your string :    "<<endl;
    gets(A);
    for(i=0; A[i]!='\0'; i++)
    {
        lenght=lenght+1;
    }
    for(i = 0; i < lenght; i++)
    {
        R[i] = A[lenght-1-i];
    }

    /*  for(i = 0; i<lenght; i++)
          {
          cout << R[i];
      }
    */
    add=lenght;

    for(i=0; i<lenght; i++)
    {
        if(A[i]!=R[i])
        {
            lenght--;
        }
    }
    if(lenght<add)
    {
        cout<<" Not palindrome........."<<endl;
    }

    if(lenght==add)
    {
        cout<<"Palindrome........."<<endl;
    }
    return 0;
}
