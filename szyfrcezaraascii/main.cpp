#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

string szyfr(int przesuniecie,string haslo)
{
    cout<<haslo<<endl;
    for(int i=0;i<=haslo.length();i++)
    {
        if(haslo[i]+przesuniecie>126)
        {
            haslo[i]=haslo[i]+(36+((126+przesuniecie)-przesuniecie));
        }
        if(haslo[i]+przesuniecie<33)
        {
            haslo[i]=haslo[i]+(88-przesuniecie);
        }
            haslo[i] += przesuniecie;


    }
    cout<<haslo<<endl;
    return haslo;
}

int main()
{
    string haslo;
    int przesuniecie;
    cout<<"Podaj o ile znakow chcesz przesunac szyfr: ";
    cin>>przesuniecie;
    szyfr(przesuniecie,haslo);
    fstream wejscie("wejscie.txt", ios::in);
    fstream wyjscie("wyjscie.txt",ios::out);
    while(!wejscie.eof())
    {
        string haslo;
        wejscie >> haslo;
        wyjscie << szyfr(przesuniecie, haslo)<< " ";
    }
    wyjscie.close();
    return 0;
}