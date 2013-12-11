@ By Galloska
@ By Galloska
@ By Galloska.
//Galloska

#include <iostream>

using namespace std;

int a[105];

int main()
{
    int n,m,tot,req,aux,cont;
    while(1){
        cin>>n;
        if(n==0)
            return 0;
        cin>>m;
        cont=0;
        int op=0;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        while(m--){
            cont=0;
            cin>>tot>>req;
            for(int j=0;j<tot;j++){
                cin>>aux;
                for(int h=0;h<n;h++){
                    if(aux==a[h])
                        cont++;
                }
            }
        if(cont<req)
                op=1;
        }
        if(op==0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
