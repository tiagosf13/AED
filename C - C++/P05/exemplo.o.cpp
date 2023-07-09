#include<iostream>


int main(){
    std :: cout << "Escreve um número" << std :: endl;
    int x;
    std :: cin >> x;  //input
    
    
    for(int i = x-1; i >= 0; i--){
        std :: cout << i<< std :: endl; //output
    }

    return 0;
}