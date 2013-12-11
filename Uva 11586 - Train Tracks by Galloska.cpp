@ By Galloska
@ By Galloska
@ By Galloska.
//Galloska

#include <iostream>

using namespace std;

string cad;

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        getline(cin,cad);
        int i=0;
        int cont=0;
        int cont2=0;
        while(cad[i]!='\0'){
            if(cad[i]=='F')
                cont++;
            else if(cad[i]=='M')
                cont2++;
            i++;
        }
        if(cont2==cont && cont+cont2>=4)
            cout<<"LOOP"<<endl;
        else
            cout<<"NO LOOP"<<endl;
    }
    return 0;
}
