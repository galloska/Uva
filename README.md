Uva 401 Palindromes
===

//Galloska Galloska Galloska Galloska
//Galloska Galloska Galloska Galloska
//Galloska Galloska Galloska Galloska
//Galloska Galloska Galloska Galloska

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int p2;
    bool p1;
    char cad[1000];
    while(gets(cad)){
        p1=true;
        p2=2;
        bool p3=false;
        int i=0,j=strlen(cad)-1;
        while(i<=j){
            if(cad[i]!=cad[j]){
                p1=false;
            }
            if((cad[i]=='E' && cad[j]=='3') || (cad[i]=='3' && cad[j]=='E') && p2!=1)
                p2=0;
            else if((cad[i]=='J' && cad[j]=='L') || (cad[i]=='L' && cad[j]=='J') && p2!=1)
                p2=0;
            else if((cad[i]=='S' && cad[j]=='2') || (cad[i]=='2' && cad[j]=='S') && p2!=1)
                p2=0;
            else if((cad[i]=='Z' && cad[j]=='5') || (cad[i]=='5' && cad[j]=='Z') && p2!=1)
                p2=0;
            else if(p2!=1 && ((cad[i]=='A' && cad[j]=='A') || (cad[i]=='H' && cad[j]=='H') || (cad[i]=='I' && cad[j]=='I') || (cad[i]=='M' && cad[j]=='M') || (cad[i]=='O' && cad[j]=='O') || (cad[i]=='T' && cad[j]=='T') || (cad[i]=='U' && cad[j]=='U') || (cad[i]=='V' && cad[j]=='V') || (cad[i]=='W' && cad[j]=='W') || (cad[i]=='1' && cad[j]=='1') || (cad[i]=='X' && cad[j]=='X') || (cad[i]=='Y' && cad[j]=='Y') || (cad[i]=='A' && cad[j]=='A') ||(cad[i]=='8' && cad[j]=='8')))
                p2=0;
            else if(cad[i]==cad[j])
                p2=1;
            else if(cad[i]!=cad[j] || (cad[i]=='0' && cad[j]=='0'))
                p2=1;
            i++;
            j--;
        }
        if(p2==1 || p2==2)
            p3=false;
        else
            p3=true;
        if(p1==false && p3==false)
            cout<<cad<<" -- is not a palindrome."<<endl;
        else if(p1==true && p3==false)
            cout<<cad<<" -- is a regular palindrome."<<endl;
        else if(p1==false && p3==true)
             cout<<cad<<" -- is a mirrored string."<<endl;
        else
            cout<<cad<<" -- is a mirrored palindrome."<<endl;
        cout<<endl;
    }
    return 0;
}

//Galloska Galloska Galloska Galloska
//Galloska Galloska Galloska Galloska
//Galloska Galloska Galloska Galloska
//Galloska Galloska Galloska Galloska
